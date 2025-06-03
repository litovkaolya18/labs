#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Node 
{
public:
    int val; // ������ �������� ����
    Node* prev; // ��������� �� ����� ���������
    Node* next; // ��������� �� ������ ���������

    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

Node* createList(const vector<int>& vals);// ������ ���������� ������
int getLength(Node* head); //��� ����� ������
Node* getNodeAt(Node* head, int index); // ��������� ���� �� �������
Node* listToBST(Node* head);//����������� ������ � ���.������
void printTree(Node* root, string prefix = "", bool isLeft = true);
void freeTree(Node* root);//��� ������������ ������