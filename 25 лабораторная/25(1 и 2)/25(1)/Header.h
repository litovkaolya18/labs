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
    // Конструктор по умолчанию
    QuadraticEquation();

    // Конструктор с двумя параметрами
    QuadraticEquation(double b_val, double c_val);

    // Конструктор с тремя параметрами
    QuadraticEquation(double a_val, double b_val, double c_val);

    // Конструктор копирования
    QuadraticEquation(const QuadraticEquation& other);
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    // Метод для вычисления корней квадратного уравнения
    vector<double> findRoots() const;

    // Декларация оператора вывода
    friend ostream& operator<<(ostream& os, const QuadraticEquation& eq);

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const QuadraticEquation& eq);
    
    // Получение коэффициентов с консоли
    static void FromConsole(double& a, double& b, double& c);

    // Получение из файла
    static void FromFile(const string& filename, double& a, double& b, double& c);

    // Рандомные числа
    static void Random(double& a, double& b, double& c);

    // Унарные операторы ++ и --
    QuadraticEquation& operator++();    // Префиксный ++ увеличивает коэффициенты a, b, c на 1
    QuadraticEquation operator++(int); // Постфиксный ++
    QuadraticEquation& operator--();    // Префиксный -- уменьшает коэффициенты a, b, c на 1.
    QuadraticEquation operator--(int); // Постфиксный --

    // Операторы приведения типа
    operator double() const;  // Возвращает дискриминант (неявное)
    explicit operator bool() const; // Проверяет наличие корней (явное)

    // Бинарные операторы == и !=
    bool operator==(const QuadraticEquation& other) const; // равны ли коэффициенты двух уравнений
    bool operator!=(const QuadraticEquation& other) const; // различны ли коэффициенты двух уравнений
};