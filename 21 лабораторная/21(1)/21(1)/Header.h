#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include <algorithm>
using namespace std;

//класс дерева поиска
class Tree 
{
public:
    class Node 
    {
    public:
        int val;
        Node* left;
        Node* right;
        Node(int v);
    };

    Tree();//создаёт пустое дерево
    ~Tree(); // освобождает память, занимаемую деревом
    void insert(int v); //вставляет новое значение в дерево
    void fillFromVector(const vector<int>& data); //заполняет дерево из вектора
    void fillFromConsole();
    bool fillFromFile(const string& filename);
    int findMax() const; //находит максимальное значение в дереве
    void printHeight() const; //высота дерева
    void printTree() const;

private:
    Node* root; //указатель на узел

    Node* insertRec(Node* node, int v); // рекурсивная реализация вставки
    void clear();
    void clearRec(Node* node); // рекурсивное удаление узлов
    int height(Node* node) const; //высота дерева
    void printTreeRec(Node* node, string prefix, bool isLeft) const;// рекурсивно печатает дерево
};
