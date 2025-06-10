#include <iostream>
#include <vector>
#include <cstdlib> // Для std::strtol
#include <cctype>  // Для std::isdigit
#include <limits>
#include <algorithm> // Для std::find_if
#include <windows.h>
#include "Header.h"
using namespace std;

// Функция для проверки ввода времени
int getValidatedInput() 
{
    int input;
    while (true) 
    {
        cout << "Введите количество секунд: ";
        cin >> input;
        // Проверка на ввод
        if (cin.fail() || input < 0) 
        { 
            cin.clear(); // Сброс состояния
            cin.ignore(1024, '\n'); // Очистка входного буфера (до 1024 символов или до новой строки)
            cout << "Пожалуйста, введите неотрицательное целое число!" << endl;
        }
        else 
        {
            // Проверка на наличие лишних символов после числа
            if (cin.peek() != '\n')
            {
                cin.clear();
                cin.ignore(1024, '\n'); // Очистка входного буфера (до 1024 символов или до новой строки)
                cout << "Ошибка: обнаружены лишние символы после числа!" << endl;
            }
            else
            {
                cin.ignore(1024, '\n');
                break;
            }
        }
    }
    return input;
}


// Функция для получения количества этажей от пользователя
int getValidatedFloorsInput() 
{
    int floors;
    while (true)
    {
        cout << "Введите количество этажей дома: ";
        cin >> floors;

        if (cin.fail() || floors < 0) // Проверка на ввод
        {
            cin.clear(); // Сброс состояния флага ошибки
            cin.ignore(1024, '\n'); // Очистка входного буфера
            cout << "Пожалуйста, введите неотрицательное целое число!" << endl;
        }
        else
        {
            // Проверка на наличие лишних символов после числа
            if (cin.peek() != '\n')
            {
                cin.clear();
                cin.ignore(1024, '\n'); // Очистка входного буфера (до 1024 символов или до новой строки)
                cout << "Ошибка: обнаружены лишние символы после числа!" << endl;
            }
            else
            {
                cin.ignore(1024, '\n');
                break;
            }
        }
    }
    return floors;
}


int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Time t1(10);         // 10 секунд
    Time t2(10000);      // 10000 секунд
    Time t3(100000);     // 100000 секунд

    // Печать
    t1.print();
    t2.print();
    t3.print();

    // Ввод времени с клавиатуры с проверкой
    int userInput = getValidatedInput();
    Time userTime(userInput);
    userTime.print();
    cout << "--------------------------------------------" << endl;


    // Работа с классом House
    House house1(1);    // 1 этаж
    House house2(5);    // 5 этажей
    House house3(23);   // 23 этажа

    // Печать описаний домов
    cout << house1.description() << endl;
    cout << house2.description() << endl;
    cout << house3.description() << endl;

    // Ввод этажей дома с клавиатуры
    int userFloors = getValidatedFloorsInput();
    House userHouse(userFloors);
    cout << userHouse.description() << endl;
    cout << "--------------------------------------------" << endl;



    // Сотрудники и отдел
    // Создаем отдел "IT" и начальника "Козлов"
    Department itDepartment("IT");
    Employee kozlov("Козлов", &itDepartment);
    itDepartment.setManager(&kozlov); // Устанавливаем Козлова как начальника

    // Создаем сотрудников
    Employee petrov("Петров", &itDepartment);
    Employee sidorov("Сидоров", &itDepartment);

    // Выводим изначально известную информацию
    cout << petrov.toString() << endl;
    cout << kozlov.toString() << endl;
    cout << sidorov.toString() << endl; 

    // Запрос на изменение информации
    while (true) 
    {
        cout << "\nЧто вы хотите сделать?" << endl;
        cout << "1. Изменить название отдела" << endl;
        cout << "2. Изменить имя начальника отдела" << endl;
        cout << "3. Изменить имя сотрудника" << endl;
        cout << "4. Узнать список всех сотрудников отдела" << endl; // Новый пункт меню
        cout << "5. Узнать сотрудников через ссылку на сотрудника (вывести список всех сотрудников отдела)" << endl; // Новый пункт
        cout << "6. Завершить" << endl;

        int choice = 0;
        while (true)
        {
            cout << "Ваш выбор: ";
            cin >> choice;

            // Проверка на корректность ввода
            if (cin.fail() || choice < 1 || choice > 6) 
            {
                cin.clear(); // Очистка состояния потока
                cin.ignore(10000, '\n'); // Игнорируем некорректные данные
                cout << "Неверный ввод. Пожалуйста, введите число от 1 до 6." << endl;
            }
            else
            {
                // Проверка на наличие лишних символов после числа
                if (cin.peek() != '\n')
                {
                    cin.clear();
                    cin.ignore(1024, '\n'); // Очистка входного буфера (до 1024 символов или до новой строки)
                    cout << "Ошибка: обнаружены лишние символы после числа!" << endl;
                }
                else
                {
                    cin.ignore(1024, '\n');
                    break;
                }
            }
        }

        if (choice == 1) 
        {
            cout << "Введите новое название отдела: ";
            string newDepartmentName;
            getline(cin, newDepartmentName);
            if (newDepartmentName.empty())
            {
                cout << "Название отдела не может быть пустым." << endl;
                continue;
            }
            itDepartment.setName(newDepartmentName);
            cout << "Название отдела изменено на: " << itDepartment.getName() << endl;

        }
        else if (choice == 2)
        {
            cout << "Введите новое имя начальника: ";
            string newManagerName;
            getline(cin, newManagerName);
            if (newManagerName.empty()) 
            {
                cout << "Имя начальника не может быть пустым." << endl;
                continue;
            }
            kozlov.setName(newManagerName);
            cout << "Имя начальника изменено на: " << kozlov.toString() << endl;
        }
        else if (choice == 3) 
        {
            cout << "Введите имя сотрудника, которого хотите изменить: ";
            string employeeName;
            getline(cin, employeeName);
            if (employeeName == "Петров") 
            {
                cout << "Введите новое имя для Петрова: ";
                string newName;
                getline(cin, newName);
                petrov.setName(newName);
            }
            else if (employeeName == "Сидоров") 
            {
                cout << "Введите новое имя для Сидорова: ";
                string newName;
                getline(cin, newName);
                sidorov.setName(newName);
            }
            else 
            {
                cout << "Сотрудник не найден." << endl;
            }

        }
        else if (choice == 4) 
        {
            // Получение списка сотрудников отдела
            cout << "Список сотрудников отдела " << itDepartment.getName() << ":" << endl;
            vector<Employee*> employees = itDepartment.getEmployees();
            for (auto employee : employees) 
            {
                cout << employee->toString() << endl;
            }
        }
        else if (choice == 5) {
            // Запрашиваем сотрудника, чьи сотрудники должны быть выведены
            cout << "Введите имя сотрудника (Петров, Сидоров, Козлов): ";
            string employeeName;
            getline(cin, employeeName);
            if (employeeName == "Петров") {
                petrov.listDepartmentEmployees();
            }
            else if (employeeName == "Сидоров") {
                sidorov.listDepartmentEmployees();
            }
            else if (employeeName == "Козлов") {
                kozlov.listDepartmentEmployees();
            }
            else {
                cout << "Сотрудник не найден." << endl;
            }

        }
        else if (choice == 6) {
            break;
        }
        else 
        {
            cout << "Неверный выбор, попробуйте снова." << endl;
        }
    }

    // Выводите текущую информацию по завершении
    cout << "\nТекущая информация о сотрудниках и отделе:" << endl;
    cout << petrov.toString() << endl;
    cout << kozlov.toString() << endl;
    cout << sidorov.toString() << endl;
    cout << "--------------------------------------------" << endl;

   

    return 0;
}
