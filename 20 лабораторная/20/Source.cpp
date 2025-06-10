#include "Header.h"
#include <iostream>
using namespace std;

// Конструктор
Time::Time(int secs) 
{
    // Приведение к значению в пределах суток
    seconds = secs % 86400; // 86400 секунд = 24 часа
}
// Метод для получения текстового представления времени
string Time::toString() const 
{
    int hours = seconds / 3600;          // Количество часов
    int minutes = (seconds % 3600) / 60; // Количество минут
    int secs = seconds % 60;              // Остаток секунд
    ostringstream oss;

    // Форматирование строки
    oss << hours << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << secs;
    return oss.str();
}
// Метод для печати времени
void Time::print() const 
{
    cout << "Время: " << toString() << endl;
}
///////////////////////////////////////////////////////////////////////////////////////


// Конструктор House
House::House(int f) : floors(f) {}

// Метод для получения текстового представления дома
string House::description() const 
{
    if (floors % 10 == 1 && floors % 100 != 11) 
    {
        return "дом с " + to_string(floors) + " этажом";
    }
    else if ((floors % 10 >= 2 && floors % 10 <= 4) && (floors % 100 < 10 || floors % 100 >= 20)) 
    {
        return "дом с " + to_string(floors) + " этажами";
    }
    else {
        return "дом с " + to_string(floors) + " этажами";
    }
}
///////////////////////////////////////////////////////////////////////////////////////


Department::Department(const string& n) : name(n), manager(nullptr) {}
void Department::addEmployee(Employee* emp) 
{
    employees.push_back(emp); // Добавление сотрудника в отдел
}

void Department::listEmployees() const 
{
    cout << "Сотрудники отдела " << name << ":" << endl;
    for (const auto& emp : employees) 
    {
        cout << emp->toString() << endl; // Вывод информации о каждом сотруднике
    }
}

void Department::setName(const string& newName) 
{
    name = newName; // Изменение названия отдела
}

const string& Department::getName() const
{
    return name; // Возврат названия отдела
}

void Department::setManager(Employee* newManager)
{
    manager = newManager; // Установка нового директора
}

vector<Employee*>& Department::getEmployees() 
{
    return employees; // Возврат списка сотрудников
}

Employee::Employee(const string& n, Department* dept) : name(n), department(dept) 
{
    department->addEmployee(this); // Добавляем сотрудника в отдел при создании
}

string Employee::toString() const 
{
    if (department->manager == this)
    {
        // Сотрудник является начальником
        return name + " начальник отдела " + department->name;
    }
    else 
    {
        // Не является начальником
        return name + " работает в отделе " + department->name + ", начальник которого " + department->manager->name;
    }
}

void Employee::setName(const string& newName) 
{
    name = newName; // Установка нового имени для сотрудника
}

void Employee::listDepartmentEmployees() const {
    if (department) {
        department->listEmployees(); // Вызов метода для отображения сотрудников отдела
    }
    else {
        cout << "Сотрудник не привязан к какому-либо отделу." << endl;
    }
}