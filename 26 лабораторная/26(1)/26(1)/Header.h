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
    int n; // Количество вершин
    vector<vector<int>> AdjacencyMatrix; // Матрица смежности
    vector<pair<int, int>> m; // Список рёбер (пары вершин)

    void extractEdges(); // Извлечение рёбер из матрицы смежности

public:
    // Конструктор: загружает граф из файла
    Graph(const string& filename);

    void loadAdjacencyMatrixFromFile(const string& filename); // Загружает матрицу смежности из файла
    void printAdjacencyMatrix() const; // Выводит матрицу смежности на консоль 
    void saveIncidenceMatrix(const string& filename) const; // Сохраняет матрицу инцидентности в файл
    void printIncidenceMatrix() const; // Выводит матрицу инцидентности на консоль
   
    void printInfo() const; // Выводит числа вершин и рёбер

    const vector<vector<int>>& getAdjacencyMatrix() const; // Метод для получения ссылки на матрицу смежности графа
    const vector<pair<int, int>>& getEdges() const; // Метод для получения ссылки на список рёбер графа
    vector<vector<int>> getIncidenceMatrix() const; // Метод для получения матрицы инцидентности графа
};
