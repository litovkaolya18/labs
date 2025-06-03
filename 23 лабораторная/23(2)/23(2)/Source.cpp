#include "Header.h"

// ������� ���� � �������� ������
void BinaryTree::insert(int v) 
{ 
    Node* newNode = new Node(v);
    //�������� �� ������ ������
    if (!root) 
    {
        root = newNode; //����� ���� ���������� ������
        return;
    }

    Node* current = root; //��� �����������
    Node* parent = nullptr; //������ ���������� ����  

    while (true) 
    {    //���������� ������� ���� ��� ��������
        parent = current; 
        if (v < current->val) 
        {   //�������� ������ �������
            current = current->left;
            if (!current) 
            {   //������� ������ ���� �����
                parent->left = newNode;
                return;
            }
        }
        else //�������� ������ ��� �����
        {   //��� ������
            current = current->right;
            if (!current) 
            {
                parent->right = newNode;
                return;
            }
        }
    }
}

// ������ ��� ���� �� ������� ������ ������ ������� �������
void BinaryTree::printLeaves(Node* node, vector<int>& leaves)
{
    if (!node) return;

    // ���� ��� �������� ����, ��������� ��� � ������
    if (!node->left && !node->right) 
    {
        leaves.push_back(node->val);
    }

    // ����������� ����� ��� ������ � ������� ���������
    printLeaves(node->left, leaves);
    printLeaves(node->right, leaves);
}
//������ �������� ����� ����� �� ������� ������
void BinaryTree::printLeftBoundary(Node* node, vector<int>& boundary) 
{
    if (!node) return;

    // �������� �� ������� ������ �������
    if (node->left) 
    {
        boundary.push_back(node->val); //������.���� ���.����
        printLeftBoundary(node->left, boundary);
    } //�� ������� ������� �������
    else if (node->right) 
    {
        boundary.push_back(node->val);
        printLeftBoundary(node->right, boundary);
    }
}

void BinaryTree::printRightBoundary(Node* node, vector<int>& boundary) 
{
    if (!node) return;

    // �������� �� ������� ������� �������
    if (node->right) 
    {
        printRightBoundary(node->right, boundary);
        boundary.push_back(node->val);
    } //������
    else if (node->left) 
    {
        printRightBoundary(node->left, boundary);
        boundary.push_back(node->val);
    }
}
//����� ������ � ���������� �������
void BinaryTree::printBoundary() 
{
    vector<int> boundary;

    if (root) 
    {
        boundary.push_back(root->val); // ��������� ������ ������

        printLeftBoundary(root->left, boundary);

        // �������� ����
        vector<int> leaves;
        printLeaves(root, leaves);
        boundary.insert(boundary.end(), leaves.begin(), leaves.end());

        printRightBoundary(root->right, boundary);

        // ����� �������
        for (int val : boundary) 
        {
            cout << val << " ";
        }

        cout << endl;
    }
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