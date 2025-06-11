#include "Header.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;

// Конструктор класса для загрузки матрицы смежности из файла
Graph::Graph(const string& filename) 
{
    loadAdjacencyMatrixFromFile(filename);
    extractEdges(); // Извлекаем рёбра после загрузки матрицы


    // если файл пуст
    ifstream inFile(filename);
    if (!inFile.is_open()) 
    {
        throw runtime_error("Файл " + filename + " не найден или не может быть открыт.");
    }
    if (inFile.peek() == ifstream::traits_type::eof())
    {
        throw runtime_error("Файл " + filename + " пуст.");
    }

    // Чтение количества вершин
    string line;
    if (!getline(inFile, line)) 
    {
        throw runtime_error("Не удалось прочитать количество вершин.");
    }

    istringstream iss(line);
    if (!(iss >> n)) 
    {
        throw runtime_error("Некорректное количество вершин.");
    }
    //проверка что количество вершин положительное
    if (n <= 0)
    {
        throw runtime_error("Количество вершин должно быть положительным.");
    }
    // Инициализация матрицы смежности
    AdjacencyMatrix.resize(n, vector<int>(n));

    // Чтение матрицы смежности
    for (int i = 0; i < n; ++i)
    {
        // Чтение строки матрицы
        if (!getline(inFile, line))
        {
            throw runtime_error("Недостаточно строк в матрице.");
        }
        // Считываем элементы из строки и заполняем соответствующую строку матрицы смежности
        istringstream rowStream(line);
        for (int j = 0; j < n; ++j)
        {
            // Считываем элементы текущей строки в матрицу смежности
            if (!(rowStream >> AdjacencyMatrix[i][j]))
            {
                throw runtime_error("Некорректный элемент матрицы в строке " + to_string(i + 1));
            }
        }
    }
    // Проверка симметричности матрицы (граф неориентированный)
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j)
        {
            if (AdjacencyMatrix[i][j] != AdjacencyMatrix[j][i]) {
                throw runtime_error("Матрица смежности не симметрична (граф должен быть неориентированным).");
            }
        }
    }

    inFile.close();
    extractEdges(); // Извлекаем рёбра
}

// Загружает матрицу смежности из файла
void Graph::loadAdjacencyMatrixFromFile(const string& filename) {
    // Открываем файл для чтения
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw runtime_error("Не удалось открыть файл " + filename);
    }

    inFile >> n; // Считываем количество вершин
    AdjacencyMatrix.resize(n, vector<int>(n, 0)); // Инициализируем матрицу смежности

    // Считываем матрицу смежности из файла
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inFile >> AdjacencyMatrix[i][j];
        }
    }
    inFile.close();
}

// Извлечение рёбер из матрицы смежности
void Graph::extractEdges() 
{
    // Проходим по всем вершинам графа
    for (int i = 0; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            // Проверяем, существует ли ребро между вершинами i и j
            if (AdjacencyMatrix[i][j] != 0) 
            {
                m.emplace_back(i, j); // Добавляем ребро
            }
        }
    }
}
// Выводит матрицу смежности на консоль 
void Graph::printAdjacencyMatrix() const {
    cout << "Матрица смежности:" << endl;
    // Перебираем строки и элементы матрицы смежности
    for (const auto& row : AdjacencyMatrix) {
        for (int val : row) {
            cout << val << " "; // Выводим значения в строке
        }
        cout << endl; // Переход на новую строку после каждой строки матрицы
    }
}


//Построение матрицы инцидентности 
vector<vector<int>> Graph::getIncidenceMatrix() const 
{
    // Создаём матрицу инцидентности : n строк × m
    // столбцов
    vector<vector<int>> incidenceMatrix(n, vector<int>(m.size(), 0));
    //заполнение матрицы
    for (size_t edgeIdx = 0; edgeIdx < m.size(); ++edgeIdx)
    {
        int u = m[edgeIdx].first;// Первая вершина ребра
        int v = m[edgeIdx].second;  // Вторая вершина ребра
        incidenceMatrix[u][edgeIdx] = 1;  // Ребро инцидентно вершине u
        incidenceMatrix[v][edgeIdx] = 1;  // Ребро инцидентно вершине v
    }
    return incidenceMatrix; // Возвращаем полученную матрицу инцидентности
}

void Graph::printIncidenceMatrix() const {
    auto incidenceMatrix = getIncidenceMatrix(); // Получаем матрицу инцидентности
    cout << "Матрица инцидентности:" << endl;
    for (const auto& row : incidenceMatrix) {
        for (int val : row) {
            cout << val << " "; // Выводим значения в строке
        }
        cout << endl; // Переход на новую строку после каждой строки
    }
}
//Сохранение матрицы инцидентности в файл
void Graph::saveIncidenceMatrix(const string& filename) const 
{
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        throw runtime_error("Не удалось создать файл " + filename);
    }

    auto incidenceMatrix = getIncidenceMatrix();
    // Записываем размер матрицы (вершины × рёбра)
    outFile << n << " " << m.size() << endl;
    // Записываем матрицу
    for (const auto& row : incidenceMatrix)
    {
        for (int val : row) 
        {
            outFile << val << " ";
        }
        outFile << endl;
    }
    outFile.close();
}


// Выводит числа вершин и рёбер
void Graph::printInfo() const 
{
    cout << "Количество вершин: " << n << endl;
    cout << "Количество ребер: " << m.size() << endl;
}

const vector<vector<int>>& Graph::getAdjacencyMatrix() const 
{   // Возвращаем ссылку на матрицу смежности
    return AdjacencyMatrix;
}

const vector<pair<int, int>>& Graph::getEdges() const 
{   // Возвращаем ссылку на вектор рёбер
    return m;
}