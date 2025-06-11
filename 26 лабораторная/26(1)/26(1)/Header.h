#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

class Graph {
private:
    int n; // ���������� ������
    vector<vector<int>> AdjacencyMatrix; // ������� ���������
    vector<pair<int, int>> m; // ������ ���� (���� ������)

    void extractEdges(); // ���������� ���� �� ������� ���������

public:
    // �����������: ��������� ���� �� �����
    Graph(const string& filename);

    void loadAdjacencyMatrixFromFile(const string& filename); // ��������� ������� ��������� �� �����
    void printAdjacencyMatrix() const; // ������� ������� ��������� �� ������� 
    void saveIncidenceMatrix(const string& filename) const; // ��������� ������� ������������� � ����
    void printIncidenceMatrix() const; // ������� ������� ������������� �� �������
   
    void printInfo() const; // ������� ����� ������ � ����

    const vector<vector<int>>& getAdjacencyMatrix() const; // ����� ��� ��������� ������ �� ������� ��������� �����
    const vector<pair<int, int>>& getEdges() const; // ����� ��� ��������� ������ �� ������ ���� �����
    vector<vector<int>> getIncidenceMatrix() const; // ����� ��� ��������� ������� ������������� �����
};
