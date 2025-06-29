﻿/*Graf2. Дано описание неориентированного графа в текстовом файле с именем FileName1. в
виде матрицы смежности. Первая строка файла содержит количество вершин графа (n), а
следующие n строк содержат матрицу смежности (a), a[i][j]=0, если ребра между
вершинами i и j не существует. Построить матрицу инцидентности данного графа и вывести
ее в файл с именем FileName2. Для справки: матрица инцидентности (b) имеет размер n x
m, m - число ребер графа, b[i][j]=1, если ребро j инцидентно вершине i, в противном случае
b[i][j]=0. Нумерацию ребер осуществлять в следующем порядке: сначала ребра,
инцидентные вершине номер 1, потом ребра инцидентные вершине номер 2 и т.д. до
вершины номер n. Ребра, инцидентные вершине с номером i перечислять в порядке
возрастания номера второй вершины, инцидентной данному ребру. При выводе в первой
строке указать размер матрицы инцидентности: числа n и m, а в следующих n строках
разместить матрицу инцидентности*/

#include <iostream>
#include <windows.h>
#include "Header.h"
using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const string inputFile = "FileName1.txt";  
    const string outputFile = "FileName2.txt";

    try 
    {
        Graph graph(inputFile); // Загружаем граф
        graph.printInfo(); // Вывод информации
        graph.printAdjacencyMatrix(); // Выводим матрицу смежности 
        graph.printIncidenceMatrix(); // Выводим матрицу инцидентности 
        graph.saveIncidenceMatrix(outputFile); // Сохранение результата
        cout << "Матрица инцидентности успешно сохранена в " << outputFile << endl;
    }
    catch (const exception& e) 
    {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
    return 0;
}
