#include "Header.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

Tree::Node::Node(int v) : val(v), left(nullptr), right(nullptr) {}

Tree::Tree() : root(nullptr) {} //создаёт пустое дерево

Tree::~Tree()
{
    clear();//для осводождений памяти
}

//для вставки нового значения
void Tree::insert(int v) 
{
    root = insertRec(root, v);
}
//находит место для нового значения
Tree::Node* Tree::insertRec(Node* node, int v) 
{
    if (!node) return new Node(v); //создаём новый узел
    if (v < node->val) // Если значение меньше текущего узла
    {  
        node->left = insertRec(node->left, v); // Идём в левое поддерево
    }
    else {
        node->right = insertRec(node->right, v); // Идём в правое поддерево
    }
    return node; // Возвращаем текущий узел
}

void Tree::clear() 
{
    clearRec(root); // Рекурсивно удаляем все узлы, начиная с корня
    root = nullptr; // Обнуляем корневой указатель
}

void Tree::clearRec(Node* node) 
{
    if (!node) return; // Если достигли пустого узла
    clearRec(node->left); // Рекурсивно удаляем левое поддерево
    clearRec(node->right); // Рекурсивно удаляем правое поддерево
    delete node; // Удаляем текущий узел
}

//заполняет дерево из вектора
void Tree::fillFromVector(const vector<int>& data) 
{
    for (int v : data) 
    {
        insert(v);
    }
}

// Метод для заполнения дерева через консольный ввод
void Tree::fillFromConsole() 
{
    clear(); //удаляет все существующие узлы
    cout << "Введите элементы дерева (целые числа), для завершения введите '-1':\n";

    while (true) 
    {
        string input; // Переменная для хранения ввода
        cin >> input;
        // Проверка на завершение ввода
        if (input == "-1")
        {
            break;
        }
        // Простая проверка что это число
        bool isNumber = true;
        bool hasMinus = false;
        for (int i = 0; i < input.length(); i++) 
        {
            char c = input[i];

            // Разрешаем минус только в начале
            if (c == '-' && i == 0) 
            {
                hasMinus = true;
                continue;
            }
            // Если символ не цифра - это не число
            if (!isdigit(c)) 
            {
                isNumber = false;
                break;
            }
        }

        if (!isNumber || (hasMinus && input.length() == 1)) 
        {
            cout << "Ошибка! Введите целое число\n";
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(10000, '\n'); // Очищаем буфер
            continue;
        }

        // Безопасное преобразование в число
        try 
        {
            int number = stoi(input);
            insert(number);
        }
        catch (...) 
        {
            cout << "Ошибка! Число слишком большое\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
// Метод для заполнения дерева из файла
bool Tree::fillFromFile(const string& filename) 
{
    clear();
    ifstream fin(filename);
    if (!fin.is_open()) 
    {
        cout << "Не удалось открыть файл: " << filename << "\n";
        return false;
    }
    int v; // Переменная для хранения чисел из файла
    while (fin >> v) 
    {
        insert(v);
    }
    fin.close();
    return true;
}

//Поиск максимального значения
int Tree::findMax() const 
{
    if (!root) //Если дерево постое
    {
        throw runtime_error("Дерево пустое");
    } 
    Node* current = root; // Начинаем с корня
    while (current->right) // Идем по правым веткам до конца
    {
        current = current->right;
    }
    return current->val; // Возвращаем значение крайнего правого узла
}

// Вычисление высоты дерева
int Tree::height(Node* node) const 
{
    if (node == nullptr)
    {
        return 0; // Высота пустого дерева
    }
    // Высота = 1 + максимальная из высот поддеревьев
    return 1 + max(height(node->left), height(node->right));
}
//Вывод высоты
void Tree::printHeight() const 
{
    int h = height(root); // Вычисляем высоту
    cout << "Высота дерева: " << h << endl;
}
//Печать дерева
void Tree::printTree() const 
{
    if (!root) 
    {
        cout << "(пустое дерево)\n";
        return;
    }
    printTreeRec(root, "", true);
}

void Tree::printTreeRec(Node* node, string prefix, bool isLeft) const 
{
    // Сначала правое поддерево (печатаем сверху)
    if (!node) return;
    if (node->right)
        printTreeRec(node->right, prefix + (isLeft ? "|   " : "    "), false);
    // Текущий узел
    cout << prefix; // Отступ
    cout << (isLeft ? "\\--" : "/--"); // Ветвление
    cout << node->val << "\n";  // Значение
    // Затем левое поддерево (печатаем снизу)
    if (node->left)
        printTreeRec(node->left, prefix + (isLeft ? "    " : "|   "), true);
}
