#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include <algorithm>
using namespace std;

//����� ������ ������
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

    Tree();//������ ������ ������
    ~Tree(); // ����������� ������, ���������� �������
    void insert(int v); //��������� ����� �������� � ������
    void fillFromVector(const vector<int>& data); //��������� ������ �� �������
    void fillFromConsole();
    bool fillFromFile(const string& filename);
    int findMax() const; //������� ������������ �������� � ������
    void printHeight() const; //������ ������
    void printTree() const;

private:
    Node* root; //��������� �� ����

    Node* insertRec(Node* node, int v); // ����������� ���������� �������
    void clear();
    void clearRec(Node* node); // ����������� �������� �����
    int height(Node* node) const; //������ ������
    void printTreeRec(Node* node, string prefix, bool isLeft) const;// ���������� �������� ������
};
