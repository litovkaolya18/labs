#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>
#include <random>
#include <stdexcept>
using namespace std;

// ����������� �� ���������
QuadraticEquation::QuadraticEquation() : a(1), b(0), c(0) {}

// ����������� � ����� �����������
QuadraticEquation::QuadraticEquation(double b_val, double c_val) : a(1), b(b_val), c(c_val) {}

// ����������� � ����� �����������
QuadraticEquation::QuadraticEquation(double a_val, double b_val, double c_val) 
{
    if (a_val == 0) 
    {
        throw invalid_argument("����������� 'a' �� ����� ���� ����� 0.");
    }
    a = a_val;
    b = b_val;
    c = c_val;
}

// ����������� ����������� 
QuadraticEquation::QuadraticEquation(const QuadraticEquation& other)
    : a(other.a), b(other.b), c(other.c) {
}

// ����� ��� ���������� ������ ����������� ���������
vector<double> QuadraticEquation::findRoots() const 
{
    vector<double> roots;
    double D = b * b - 4 * a * c;  // ��������� ������������

    if (D < 0) 
    {
        return roots;  // ��� �������������� ������ - ���������� ������ ������
    }
    else if (D == 0) 
    {
        roots.push_back(-b / (2 * a));  // ���� ������
    }
    else 
    {
        roots.push_back((-b + sqrt(D)) / (2 * a));  // ������ ������
        roots.push_back((-b - sqrt(D)) / (2 * a));  // ������ ������
    }
    return roots;
}

// ���������� ��������� ������ ��� ��������� ����������� ���������
ostream& operator<<(ostream& os, const QuadraticEquation& eq)
{
    os << eq.a << "x^2";  // ������� ������������ ����
    //������� b � c ���� �� ����� 0
    if (eq.b != 0) 
    {
        os << (eq.b > 0 ? " + " : " - ") << abs(eq.b) << "x";
    }
    if (eq.c != 0)
    {
        os << (eq.c > 0 ? " + " : " - ") << abs(eq.c);
    }
    os << " = 0"; // ��������� ���������
    return os;
}

// ��������� ������������� � �������
void QuadraticEquation::FromConsole(double& a, double& b, double& c)
{
    while (true)
    {
        try
        {
            cout << "������� ������������ ����������� ��������� a, b, c (a != 0):" << endl;
            cout << "a: ";
            // ���� � �������� �������������
            if (!(cin >> a)) 
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("����������� 'a' ������ ���� ������.");
            }

            if (a == 0) 
            {
                throw invalid_argument("����������� 'a' �� ����� ���� ����� 0.");
            }

            cout << "b: ";
            if (!(cin >> b)) 
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("����������� 'b' ������ ���� ������.");
            }

            cout << "c: ";
            if (!(cin >> c))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("����������� 'c' ������ ���� ������.");
            }

            break;
        }
        catch (const invalid_argument& e) 
        {
            cerr << "������: " << e.what() << endl;
        }
    }
}

// ��������� ������������� �� �����
void QuadraticEquation::FromFile(const string& filename, double& a, double& b, double& c) 
{
    ifstream file(filename);
    if (!file)
    {
        throw runtime_error("�� ������� ������� ����: " + filename);
    }
    if(!(file >> a >> b >> c))
    {
        throw runtime_error("������ ������ ������������� �� �����");
    }
    if (a==0) 
    {
        throw invalid_argument("����������� 'a' �� ����� ���� ����� 0");
    }
}

// ��������� ��������� �������������
void QuadraticEquation::Random(double& a, double& b, double& c)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-100,100);

    // ��������� ���������� a, �� ������� 0
    do 
    {
        a = dis(gen);
    } while (a == 0);
    // ��������� ��������� �������������
    b = dis(gen);
    c = dis(gen);
}

// ���������� ++ (����������� ������������ �� 1)
QuadraticEquation& QuadraticEquation::operator++()
{
    ++a;
    ++b;
    ++c;
    return *this;
}

// ����������� ++ (���������� ������ ��������)
QuadraticEquation QuadraticEquation::operator++(int)
{
    QuadraticEquation temp = *this;
    ++(*this); // ���������� ���������� ++
    return temp;
}

// ���������� -- (��������� ������������ �� 1)
QuadraticEquation& QuadraticEquation::operator--()
{
    --a;
    --b;
    --c;
    return *this;
}

// ����������� -- (���������� ������ ��������)
QuadraticEquation QuadraticEquation::operator--(int)
{
    QuadraticEquation temp = *this;
    --(*this); // ���������� ���������� --
    return temp;
}

// ���������� � double (������������)
QuadraticEquation::operator double() const
{
    return b * b - 4 * a * c;
}

// ����� ���������� � bool (���� �� �����?)
QuadraticEquation::operator bool() const
{
    return (b * b - 4 * a * c) >= 0;
}

// �������� == (���������� ������������)
bool QuadraticEquation::operator==(const QuadraticEquation& other) const
{
    return (a == other.a) && (b == other.b) && (c == other.c);
}

// �������� != (��������� ����������� �������������)
bool QuadraticEquation::operator!=(const QuadraticEquation& other) const
{
    return !(*this == other); // ���������� ��� ������������� ==
}

