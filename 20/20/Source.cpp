#include "Header.h"
#include <iostream>
using namespace std;

// �����������
Time::Time(int secs) 
{
    // ���������� � �������� � �������� �����
    seconds = secs % 86400; // 86400 ������ = 24 ����
}
// ����� ��� ��������� ���������� ������������� �������
string Time::toString() const 
{
    int hours = seconds / 3600;          // ���������� �����
    int minutes = (seconds % 3600) / 60; // ���������� �����
    int secs = seconds % 60;              // ������� ������
    ostringstream oss;

    // �������������� ������
    oss << hours << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << secs;
    return oss.str();
}
// ����� ��� ������ �������
void Time::print() const 
{
    cout << "�����: " << toString() << endl;
}
///////////////////////////////////////////////////////////////////////////////////////


// ����������� House
House::House(int f) : floors(f) {}

// ����� ��� ��������� ���������� ������������� ����
string House::description() const 
{
    if (floors % 10 == 1 && floors % 100 != 11) 
    {
        return "��� � " + to_string(floors) + " ������";
    }
    else if ((floors % 10 >= 2 && floors % 10 <= 4) && (floors % 100 < 10 || floors % 100 >= 20)) 
    {
        return "��� � " + to_string(floors) + " �������";
    }
    else {
        return "��� � " + to_string(floors) + " �������";
    }
}
///////////////////////////////////////////////////////////////////////////////////////


Department::Department(const string& n) : name(n), manager(nullptr) {}
void Department::addEmployee(Employee* emp) 
{
    employees.push_back(emp); // ���������� ���������� � �����
}

void Department::listEmployees() const 
{
    cout << "���������� ������ " << name << ":" << endl;
    for (const auto& emp : employees) 
    {
        cout << emp->toString() << endl; // ����� ���������� � ������ ����������
    }
}

void Department::setName(const string& newName) 
{
    name = newName; // ��������� �������� ������
}

const string& Department::getName() const
{
    return name; // ������� �������� ������
}

void Department::setManager(Employee* newManager)
{
    manager = newManager; // ��������� ������ ���������
}

vector<Employee*>& Department::getEmployees() 
{
    return employees; // ������� ������ �����������
}

Employee::Employee(const string& n, Department* dept) : name(n), department(dept) 
{
    department->addEmployee(this); // ��������� ���������� � ����� ��� ��������
}

string Employee::toString() const 
{
    if (department->manager == this)
    {
        // ��������� �������� �����������
        return name + " ��������� ������ " + department->name;
    }
    else 
    {
        // �� �������� �����������
        return name + " �������� � ������ " + department->name + ", ��������� �������� " + department->manager->name;
    }
}

void Employee::setName(const string& newName) 
{
    name = newName; // ��������� ������ ����� ��� ����������
}

void Employee::listDepartmentEmployees() const {
    if (department) {
        department->listEmployees(); // ����� ������ ��� ����������� ����������� ������
    }
    else {
        cout << "��������� �� �������� � ������-���� ������." << endl;
    }
}