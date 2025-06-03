/*TreeWork6. Дано дерево поиска и указатель корень дерева P1. Необходимо вывести
максимальное значение в дереве. Решение должно иметь сложность по времени исполнения
T(n) = O(log n), где n - число вершин в дереве. */
#include "Header.h"
#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

// Функция для безопасного ввода числа с проверкой
int getValidatedInt(const string& prompt, int minVal, int maxVal)
{
    int value; // Переменная для хранения введенного числа
    while (true)
    {
        cout << prompt; // Вывод подсказки для пользователя
        cin >> value;
        //Ошибка ввода или число вне диапазона
        if (cin.fail() || value < minVal || value > maxVal) 
        {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Ошибка: введите число от " << minVal << " до " << maxVal << endl;
        }
        else if (cin.peek() != '\n') // Во входном потоке остались лишние символы
        {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Ошибка: обнаружены лишние символы после числа!" << endl;
        }
        else  // Успешный ввод
        {
            cin.ignore(1024, '\n');
            return value;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Tree myTree;
    vector<int> randomNumbers; // Вектор для хранения случайных чисел

    while (true)
    {
        cout << "Выберите источник данных для заполнения дерева:\n"
            "1. Консоль\n"
            "2. Случайные значения\n"
            "3. Из файла\n"
            "0. Выход\n";

        int choice = getValidatedInt("Ваш выбор: ", 0, 3);

        if (choice == 0)
        {
            cout << "Выход из программы.\n";
            break;
        }

        switch (choice) 
        {
        case 1:
            myTree.fillFromConsole();
            break;
        case 2:
        {
            int count, minVal, maxVal;
            cout << "Введите количество элементов: ";
            cin >> count;
            cout << "Введите минимальное значение: ";
            cin >> minVal;
            cout << "Введите максимальное значение: ";
            cin >> maxVal;

            if (minVal > maxVal)
            {
                cout << "Ошибка: минимальное значение больше максимального!\n";
                continue;
            }

            randomNumbers.clear(); // Очистка вектора
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(minVal, maxVal);

            // Генерация случайных чисел
            for (int i = 0; i < count; i++) 
            {
                randomNumbers.push_back(dis(gen));
            }

            // Вывод сгенерированных чисел
            cout << "\nСгенерированные случайные числа:\n";
            for (int num : randomNumbers)
            {
                cout << num << " ";
            }
            cout << endl;

            // Заполнение дерева сгенерированными числами
            myTree.fillFromVector(randomNumbers);
            cout << "\nДерево успешно создано на основе сгенерированных чисел.\n";
            break;
        }
        case 3:
        {
            cin.ignore(1024, '\n');
            string filename;
            cout << "Введите имя файла: ";
            getline(cin, filename);
            if (!myTree.fillFromFile(filename)) 
            {
                cout << "Загрузка из файла не удалась.\n";
                continue;
            }
            break;
        }
        default:
            cout << "Неверный выбор, попробуйте снова.\n";
            continue;
        }

        cout << "\nПостроенное дерево:\n";
        myTree.printTree();

        // Печать высоты дерева
        //myTree.printHeight();

        try 
        {
            cout << "\nМаксимальное значение в дереве: " << myTree.findMax() << "\n";
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;
        }
    }
    return 0;
}
