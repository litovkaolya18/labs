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
        Node* parent; //указатель на родительский узел
        bool burnt; //дл€ того чтоб узнать сгорел ли узел 

        Node(int value);
    };
    BinaryTree();
    void insert(int value);
    void burnFire(Node* start);
    void print();
    Node* findNode(int value); // ћетод дл€ поиска узла
private:
    Node* root;
    Node* insertRec(Node* node, int value, Node* parent);
    void printTree(Node* node, const std::string& prefix, bool isLeft); // Ќовый метод дл€ визуального представлени€ дерева
    void printTree(Node* node); // ќбертка, чтобы не передавать дополнительные параметры
};