//TreeFun8.Реализовать обход кромки кроны бинарного дерева против 
//часовой стрелки.Обход начинается в корне дерева.
#include <iostream>
#include <windows.h>
#include "Header.h"

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
    cin >> choice;

    if (choice == 1)
    {
        int input;
        cout << "Введите значения для вставки в бинарное дерево (введите -1 для завершения):\n";
        while (true) 
        {
            cin >> input;
            if (input == -1) break;
            tree.insert(input);
        }
    }
    else if (choice == 2) 
    {
        int n;
        cout << "Введите количество случайных значений для вставки: ";
        cin >> n;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100); // Генерация случайных чисел от 1 до 100

        vector<int> randomNumbers; // Вектор для хранения случайных чисел

        for (int i = 0; i < n; ++i) 
        {
            int number = dis(gen);
            randomNumbers.push_back(number); // Сохраняем случайное число в вектор
            tree.insert(number);
        }
        // Выводим список случайных чисел
        cout << "Сгенерированные случайные числа: ";
        for (const auto& num : randomNumbers) 
        {
            cout << num << " "; // Вывод каждого случайного числа
        }
        cout << endl;
    }
    else 
    {
        cout << "Некорректный выбор.\n";
        return 1;
    }

    cout << "\nВывод дерева боком:\n";
    tree.printTree(tree.root, "", false);

    cout << "\nГраницы дерева против часовой стрелки:\n";
    tree.printBoundary();

    return 0;
}