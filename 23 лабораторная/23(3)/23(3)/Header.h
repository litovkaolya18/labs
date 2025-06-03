#pragma once
#include <iostream>
#include <queue>

class BinaryTree 
{
public:
    struct Node
    {
        int val;
        Node* left;
        Node* right;
        Node* parent; //��������� �� ������������ ����
        bool burnt; //��� ���� ���� ������ ������ �� ���� 

        Node(int value);
    };
    BinaryTree();
    void insert(int value);
    void burnFire(Node* start);
    void print();
    Node* findNode(int value); // ����� ��� ������ ����
private:
    Node* root;
    Node* insertRec(Node* node, int value, Node* parent);
    void printTree(Node* node, const std::string& prefix, bool isLeft); // ����� ����� ��� ����������� ������������� ������
    void printTree(Node* node); // �������, ����� �� ���������� �������������� ���������
};