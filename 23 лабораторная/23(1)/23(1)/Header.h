#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Node 
{
public:
    int val; // хранит значение узла
    Node* prev; // указатель на левое поддерево
    Node* next; // указатель на правое поддерево

    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

Node* createList(const vector<int>& vals);// создаёт двусвязный список
int getLength(Node* head); //для длины списка
Node* getNodeAt(Node* head, int index); // получение узла по индексу
Node* listToBST(Node* head);//преобразует список в бин.дерево
void printTree(Node* root, string prefix = "", bool isLeft = true);
void freeTree(Node* root);//для освобождения памяти