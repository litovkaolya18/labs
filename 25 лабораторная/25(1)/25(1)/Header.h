#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

class QuadraticEquation 
{
private:
    double a;
    double b;
    double c;

public:
    // ����������� �� ���������
    QuadraticEquation();

    // ����������� � ����� �����������
    QuadraticEquation(double b_val, double c_val);

    // ����������� � ����� �����������
    QuadraticEquation(double a_val, double b_val, double c_val);

    // ����������� �����������
    QuadraticEquation(const QuadraticEquation& other);
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    // ����� ��� ���������� ������ ����������� ���������
    vector<double> findRoots() const;

    // ���������� ��������� ������
    friend ostream& operator<<(ostream& os, const QuadraticEquation& eq);

    // ���������� ��������� ������
    friend ostream& operator<<(ostream& os, const QuadraticEquation& eq);
    
    // ��������� ������������� � �������
    static void FromConsole(double& a, double& b, double& c);

    // ��������� �� �����
    static void FromFile(const string& filename, double& a, double& b, double& c);

    // ��������� �����
    static void Random(double& a, double& b, double& c);

    // ������� ��������� ++ � --
    QuadraticEquation& operator++();    // ���������� ++ ����������� ������������ a, b, c �� 1
    QuadraticEquation operator++(int); // ����������� ++
    QuadraticEquation& operator--();    // ���������� -- ��������� ������������ a, b, c �� 1.
    QuadraticEquation operator--(int); // ����������� --

    // ��������� ���������� ����
    operator double() const;  // ���������� ������������ (�������)
    explicit operator bool() const; // ��������� ������� ������ (�����)

    // �������� ��������� == � !=
    bool operator==(const QuadraticEquation& other) const; // ����� �� ������������ ���� ���������
    bool operator!=(const QuadraticEquation& other) const; // �������� �� ������������ ���� ���������
};