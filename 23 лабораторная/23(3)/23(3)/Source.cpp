#include <random>
#include "Header.h"
using namespace std;

BinaryTree::Node::Node(int value) 
    : val(value), left(nullptr), right(nullptr), parent(nullptr), burnt(false) {}

BinaryTree::BinaryTree() : root(nullptr) {}

//������ ������ 
BinaryTree::Node* BinaryTree::insertRec(Node* node, int value, Node* parent) 
{
    if (!node) 
    {
        Node* newNode = new Node(value);
        newNode->parent = parent; // ������������� ��������
        return newNode;
    }
    if (value < node->val)
    {
        node->left = insertRec(node->left, value, node);
    }
    else 
    {
        node->right = insertRec(node->right, value, node);
    }
    return node;
}
// ������� ���� � �������� ������
void BinaryTree::insert(int value)
{
    root = insertRec(root, value, nullptr);
}


// ����� ������ �����
void BinaryTree::printTree(Node* node, const string& prefix, bool isLeft) 
{
    if (!node) return;

    // ������� ������ ���������
    if (node->right)
        printTree(node->right, prefix + (isLeft ? "|   " : "    "), false);

    // ������� ������� ����
    cout << prefix;
    if (isLeft)
        cout << "\\--";  // ����� ���������
    else
        cout << "/--";   // ������ ���������
    cout << node->val << "\n"; // ����� �������� ����

    // ������� ����� ���������
    if (node->left)
        printTree(node->left, prefix + (isLeft ? "    " : "|   "), true);
}

void BinaryTree::printTree(Node* node) 
{
    printTree(node, "", false); // ����� � ������ ��������� � ��� ������� ���������
}

void  BinaryTree::print() 
{
    if (!root) 
    {
        cout << "������ ������!" << endl;
        return;
    }
    printTree(root);
}
// ����� ����� � ��������
void BinaryTree::burnFire(Node* start)
{
    if (!start) 
    {
        cout << "������: ��������� ���� ����� ����!" << endl;
        return;
    }
    queue<Node*> q;
    q.push(start);
  
    while (!q.empty()) 
    {
        Node* current = q.front();
        q.pop();
        // ���� ���� ��� �� ������
        if (!current->burnt) 
        {
            cout << "����� ���� �� ���������: " << current->val << endl; // ������� ����, ������� �����
            current->burnt = true; // ������������� ���� ��������

            // ��������� �����
            if (current->left) 
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }

            // ��������� ��������
            if (current->parent) 
            {
                q.push(current->parent);
            }
        }
    }
}
BinaryTree::Node* BinaryTree::findNode(int value)
{
    queue<Node*> q;
    if (!root) return nullptr;
    q.push(root);

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        if (current->val == value) 
        {
            return current; // ���������� ��������� ����
        }
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return nullptr; // ���� ���� �� ������
}

