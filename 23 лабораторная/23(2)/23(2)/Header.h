#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;

class Node 
{
public:
    int val; // ������ �������� ����
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BinaryTree 
{
public:
    Node* root;//��������� �� ������

    BinaryTree() : root(nullptr) {}

    void insert(int v);//��� ������� �������� � ������
    void printTree(Node* node, const string& prefix, bool isLeft);//��� ������ ������
    void printBoundary(); //��� ������ ������ ������
private:
    void printLeaves(Node* node, vector<int>& leaves); // ������ ��� ���� �� ������� ������ ������ ������� �������
    void printLeftBoundary(Node* node, vector<int>& boundary);
    void printRightBoundary(Node* node, vector<int>& boundary);
};