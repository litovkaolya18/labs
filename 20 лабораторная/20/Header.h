#pragma once
#include <string>
#include <sstream>
#include <vector> 
#include <iomanip>
#include <iostream>
using namespace std;

//класс Время
class Time 
{
private:
    // Секунды с начала суток
    int seconds;
public:
    // Конструктор
    Time(int secs);

    // Метод для получения текстового представления времени
    string toString() const;

    // Метод для печати времени
    void print() const;
};



// Класс Дом
class House 
{
private:
    int floors; // Количество этажей
    
public:
    // Конструктор
    House(int f);

    // Метод для получения текстового представления дома
    string description() const;
};




//классы сотрудники и отделы
class Employee;
class Department {
public:
    string name; //имя отдела 
    Employee* manager; // Указатель на директора 
    vector<Employee*> employees; // Список сотрудников

    Department(const string& n); //создаёт отдел с именем 
    void addEmployee(Employee* emp); // добавляет сотрудника в отдел
    void listEmployees() const; //Выводит список всех сотрудников отдела
    void setName(const string& newName);  //Устанавливает название отдела
    const string& getName() const; //получает название отдела
    void setManager(Employee* newManager);//директор 
    vector<Employee*>& getEmployees(); // Возвращает список сотрудников
};

class Employee 
{
public:
    string name;
    Department* department; //  указатель на отдел, где работает сотрудник

    Employee(const string& n, Department* dept);
    string toString() const;
    void setName(const string& newName); //Изменяет имя сотрудника
    void listDepartmentEmployees() const; //Выводит список всех сотрудников отдела
};