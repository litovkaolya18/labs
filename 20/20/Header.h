#pragma once
#include <string>
#include <sstream>
#include <vector> 
#include <iomanip>
#include <iostream>
using namespace std;

//����� �����
class Time 
{
private:
    // ������� � ������ �����
    int seconds;
public:
    // �����������
    Time(int secs);

    // ����� ��� ��������� ���������� ������������� �������
    string toString() const;

    // ����� ��� ������ �������
    void print() const;
};



// ����� ���
class House 
{
private:
    int floors; // ���������� ������
    
public:
    // �����������
    House(int f);

    // ����� ��� ��������� ���������� ������������� ����
    string description() const;
};




//������ ���������� � ������
class Employee;
class Department {
public:
    string name; //��� ������ 
    Employee* manager; // ��������� �� ��������� 
    vector<Employee*> employees; // ������ �����������

    Department(const string& n); //������ ����� � ������ 
    void addEmployee(Employee* emp); // ��������� ���������� � �����
    void listEmployees() const; //������� ������ ���� ����������� ������
    void setName(const string& newName);  //������������� �������� ������
    const string& getName() const; //�������� �������� ������
    void setManager(Employee* newManager);//�������� 
    vector<Employee*>& getEmployees(); // ���������� ������ �����������
};

class Employee 
{
public:
    string name;
    Department* department; //  ��������� �� �����, ��� �������� ���������

    Employee(const string& n, Department* dept);
    string toString() const;
    void setName(const string& newName); //�������� ��� ����������
    void listDepartmentEmployees() const; //������� ������ ���� ����������� ������
};