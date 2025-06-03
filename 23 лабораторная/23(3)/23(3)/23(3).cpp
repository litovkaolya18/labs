//TreeFun11.В одном из узлов бинарного дерева начинается пожар.Пожар распространяется
//только по ветвям во все стороны(и на потомков, и на родителей) с одинаковой скоростью.Для
//заданного бинарного дерева и выбранного узла, с которого начинается пожар, требуется
//вывести все узлы дерева в том порядке, в котором они будут сгорать.

#include <iostream>
#include <queue>
#include <random>
#include <windows.h>
#include "Header.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    BinaryTree tree;

    int choice;
    cout << "Выберите способ ввода дерева:\n"
        << "1. Ввод с консоли\n"
        << "2. Случайная генерация\n"
        << "Введите номер опции: ";
  
    // Обработка ввода для выбора опции
    while (!(cin >> choice) || (choice != 1 && choice != 2))
    {
        cin.clear();
        cin.ignore(10000, '\n'); // Используем большое число вместо max
        cout << "Некорректный ввод. Пожалуйста, введите 1 или 2: ";
    }

    if (choice == 1)
    {
        cout << "Введите значения для вставки в бинарное дерево (введите -1 для завершения):\n";
        int input;
        while (true) 
        {
            // Проверка на корректность ввода числа
            while (!(cin >> input)) 
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Некорректный ввод. Пожалуйста, введите целое число или -1 для завершения: ";
            }
            if (input == -1) break;
            tree.insert(input);
        }
    }
    else if (choice == 2)
    {
        int n;
        cout << "Введите количество случайных значений для вставки: ";

        // Проверка на корректность ввода количества
        while (!(cin >> n) || n <= 0) 
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Некорректный ввод. Пожалуйста, введите положительное целое число: ";
        } 

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100); // Генерация случайных чисел от 1 до 100

        cout << "Генерируем дерево со случайными значениями: ";
        for (int i = 0; i < n; ++i)
        {
            int number = dis(gen);
            cout << number << " ";
            tree.insert(number);
        }
        cout << endl;
    }
    else 
    {
        cout << "Некорректный выбор.\n";
        return 1;
    }

    cout << "\nДерево:\n";
    tree.print(); // Выводим дерево
    cout << endl;

    int fireNodeValue;
    cout << "Введите значение узла, с которого начинается пожар: ";
    
    // Проверка на корректность ввода узла для пожара
    while (!(cin >> fireNodeValue)) 
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
    }
    BinaryTree::Node* fireNode = tree.findNode(fireNodeValue);
    
    if (fireNode)
    {
        cout << "\nПорядок горения узлов: ";
        tree.burnFire(fireNode); // Начинаем пожар с найденного узла
    }
    else 
    {
        cout << "Узел с таким значением не найден.\n";
    }
    return 0;
}
