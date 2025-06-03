#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;

class Node 
{
public:
    int val; // хранит значение узла
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BinaryTree 
{
public:
    Node* root;//указатель на корень

    BinaryTree() : root(nullptr) {}

    void insert(int v);//для вставки значения в дерево
    void printTree(Node* node, const string& prefix, bool isLeft);//для вывода дерева
    void printBoundary(); //для вывода границ дерева
private:
    void printLeaves(Node* node, vector<int>& leaves); // Вводит все узлы на границе дерева против часовой стрелки
    void printLeftBoundary(Node* node, vector<int>& boundary);
    void printRightBoundary(Node* node, vector<int>& boundary);
};