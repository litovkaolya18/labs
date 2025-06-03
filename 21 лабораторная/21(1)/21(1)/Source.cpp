#include "Header.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

Tree::Node::Node(int v) : val(v), left(nullptr), right(nullptr) {}

Tree::Tree() : root(nullptr) {} //������ ������ ������

Tree::~Tree()
{
    clear();//��� ������������ ������
}

//��� ������� ������ ��������
void Tree::insert(int v) 
{
    root = insertRec(root, v);
}
//������� ����� ��� ������ ��������
Tree::Node* Tree::insertRec(Node* node, int v) 
{
    if (!node) return new Node(v); //������ ����� ����
    if (v < node->val) // ���� �������� ������ �������� ����
    {  
        node->left = insertRec(node->left, v); // ��� � ����� ���������
    }
    else {
        node->right = insertRec(node->right, v); // ��� � ������ ���������
    }
    return node; // ���������� ������� ����
}

void Tree::clear() 
{
    clearRec(root); // ���������� ������� ��� ����, ������� � �����
    root = nullptr; // �������� �������� ���������
}

void Tree::clearRec(Node* node) 
{
    if (!node) return; // ���� �������� ������� ����
    clearRec(node->left); // ���������� ������� ����� ���������
    clearRec(node->right); // ���������� ������� ������ ���������
    delete node; // ������� ������� ����
}

//��������� ������ �� �������
void Tree::fillFromVector(const vector<int>& data) 
{
    for (int v : data) 
    {
        insert(v);
    }
}

// ����� ��� ���������� ������ ����� ���������� ����
void Tree::fillFromConsole() 
{
    clear(); //������� ��� ������������ ����
    cout << "������� �������� ������ (����� �����), ��� ���������� ������� '-1':\n";

    while (true) 
    {
        string input; // ���������� ��� �������� �����
        cin >> input;
        // �������� �� ���������� �����
        if (input == "-1")
        {
            break;
        }
        // ������� �������� ��� ��� �����
        bool isNumber = true;
        bool hasMinus = false;
        for (int i = 0; i < input.length(); i++) 
        {
            char c = input[i];

            // ��������� ����� ������ � ������
            if (c == '-' && i == 0) 
            {
                hasMinus = true;
                continue;
            }
            // ���� ������ �� ����� - ��� �� �����
            if (!isdigit(c)) 
            {
                isNumber = false;
                break;
            }
        }

        if (!isNumber || (hasMinus && input.length() == 1)) 
        {
            cout << "������! ������� ����� �����\n";
            cin.clear(); // ���������� ���� ������
            cin.ignore(10000, '\n'); // ������� �����
            continue;
        }

        // ���������� �������������� � �����
        try 
        {
            int number = stoi(input);
            insert(number);
        }
        catch (...) 
        {
            cout << "������! ����� ������� �������\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
// ����� ��� ���������� ������ �� �����
bool Tree::fillFromFile(const string& filename) 
{
    clear();
    ifstream fin(filename);
    if (!fin.is_open()) 
    {
        cout << "�� ������� ������� ����: " << filename << "\n";
        return false;
    }
    int v; // ���������� ��� �������� ����� �� �����
    while (fin >> v) 
    {
        insert(v);
    }
    fin.close();
    return true;
}

//����� ������������� ��������
int Tree::findMax() const 
{
    if (!root) //���� ������ ������
    {
        throw runtime_error("������ ������");
    } 
    Node* current = root; // �������� � �����
    while (current->right) // ���� �� ������ ������ �� �����
    {
        current = current->right;
    }
    return current->val; // ���������� �������� �������� ������� ����
}

// ���������� ������ ������
int Tree::height(Node* node) const 
{
    if (node == nullptr)
    {
        return 0; // ������ ������� ������
    }
    // ������ = 1 + ������������ �� ����� �����������
    return 1 + max(height(node->left), height(node->right));
}
//����� ������
void Tree::printHeight() const 
{
    int h = height(root); // ��������� ������
    cout << "������ ������: " << h << endl;
}
//������ ������
void Tree::printTree() const 
{
    if (!root) 
    {
        cout << "(������ ������)\n";
        return;
    }
    printTreeRec(root, "", true);
}

void Tree::printTreeRec(Node* node, string prefix, bool isLeft) const 
{
    // ������� ������ ��������� (�������� ������)
    if (!node) return;
    if (node->right)
        printTreeRec(node->right, prefix + (isLeft ? "|   " : "    "), false);
    // ������� ����
    cout << prefix; // ������
    cout << (isLeft ? "\\--" : "/--"); // ���������
    cout << node->val << "\n";  // ��������
    // ����� ����� ��������� (�������� �����)
    if (node->left)
        printTreeRec(node->left, prefix + (isLeft ? "    " : "|   "), true);
}
