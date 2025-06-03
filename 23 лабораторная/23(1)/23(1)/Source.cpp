#include "Header.h"

// ������� ���������� ������ �� �������
Node* createList(const vector<int>& vals)
{
    Node* head = nullptr; // ������ �� ������ ���� ������
    Node* tail = nullptr; // ������ �� ��������� ���� ������
    for (int v : vals) 
    {
        //�������� ������ ���� � ������� ���������
        Node* node = new Node(v);
        if (!head)
            head = tail = node;
        else 
        {
            tail->next = node; // ���������� ���� ��������� �� ����� ����� next
            node->prev = tail; // ��������� ��������� prev �� ����� ����
            tail = node;       // ��������� ����� ����� ��������� �� ��������� ����
        }
    }
    return head;
}

// ���������� ����� ����������� ������
int getLength(Node* head) 
{
    int len = 0; // ��� �������� �����
    while (head) 
    {
        len++;
        head = head->next; // ������� � ���������� ����
    }
    return len;
}

// ��������� ���� �� �������
Node* getNodeAt(Node* head, int index) 
{
    if (index < 0) return nullptr;
    for (int i = 0; i < index && head; i++) 
    {
        head = head->next; // �� ������ �������� ���������� head ����������� �� ��������� ����
    }
    return head;
}

// ����������� ������� ������ � ���������������� �������� ������ ������(BST)
Node* listToBST(Node* head) 
{
    if (!head) return nullptr;

    int len = getLength(head);//�������� ����� ������
    if (len == 1) 
    { 
        head->prev = nullptr;
        head->next = nullptr;
        return head;
    }

    // ���������� �������� ����
    int midIdx = len / 2;
    Node* mid = getNodeAt(head, midIdx); // ���������� ��������� �� ���� � ���� ��������

    // ���������� �������� �����
    if (mid->prev) mid->prev->next = nullptr; // ��������� ����� �����
    if (mid->next) mid->next->prev = nullptr; // ��������� ������ �����

    // ���������� ������ �� ��� �����
    Node* leftHead = (head == mid) ? nullptr : head; // ����� ���������
    Node* rightHead = mid->next; // ������ ���������

    // ��������� ���������� �������� ����
    mid->prev = nullptr;
    mid->next = nullptr;

    // ����������� ������ ��� ���������� �����������
    mid->prev = listToBST(leftHead);
    mid->next = listToBST(rightHead);

    return mid; // ������� ����� ���������
}

// ����� ������ � ������� '/' � '\'
void printTree(Node* root, string prefix, bool isLeft) {
    if (!root) return;

    // ������� ������ ���������
    if (root->next)
        printTree(root->next, prefix + (isLeft ? "|   " : "    "), false);

    // ������� ������� ����
    cout << prefix;
    if (isLeft)
        cout << "\\--";  // ����� ���������
    else
        cout << "/--";   // ������ ���������
    cout << root->val << "\n"; // ����� �������� ����

    // ������� ����� ���������
    if (root->prev)
        printTree(root->prev, prefix + (isLeft ? "    " : "|   "), true);
}

// ������������ ������ ��������� ������
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->prev);
    freeTree(root->next);
    delete root;
}
