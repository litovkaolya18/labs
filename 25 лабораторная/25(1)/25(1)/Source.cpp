#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>
#include <random>
#include <stdexcept>
using namespace std;

// Конструктор по умолчанию
QuadraticEquation::QuadraticEquation() : a(1), b(0), c(0) {}

// Конструктор с двумя параметрами
QuadraticEquation::QuadraticEquation(double b_val, double c_val) : a(1), b(b_val), c(c_val) {}

// Конструктор с тремя параметрами
QuadraticEquation::QuadraticEquation(double a_val, double b_val, double c_val) 
{
    if (a_val == 0) 
    {
        throw invalid_argument("Коэффициент 'a' не может быть равен 0.");
    }
    a = a_val;
    b = b_val;
    c = c_val;
}

// Конструктор копирования 
QuadraticEquation::QuadraticEquation(const QuadraticEquation& other)
    : a(other.a), b(other.b), c(other.c) {
}

// Метод для вычисления корней квадратного уравнения
vector<double> QuadraticEquation::findRoots() const 
{
    vector<double> roots;
    double D = b * b - 4 * a * c;  // Вычисляем дискриминант

    if (D < 0) 
    {
        return roots;  // Нет действительных корней - возвращаем пустой вектор
    }
    else if (D == 0) 
    {
        roots.push_back(-b / (2 * a));  // Один корень
    }
    else 
    {
        roots.push_back((-b + sqrt(D)) / (2 * a));  // Первый корень
        roots.push_back((-b - sqrt(D)) / (2 * a));  // Второй корень
    }
    return roots;
}

// Перегрузка оператора вывода для красивого отображения уравнения
ostream& operator<<(ostream& os, const QuadraticEquation& eq)
{
    os << eq.a << "x^2";  // Выводим квадратичный член
    //выводим b и c если не равны 0
    if (eq.b != 0) 
    {
        os << (eq.b > 0 ? " + " : " - ") << abs(eq.b) << "x";
    }
    if (eq.c != 0)
    {
        os << (eq.c > 0 ? " + " : " - ") << abs(eq.c);
    }
    os << " = 0"; // Завершаем уравнение
    return os;
}

// Получение коэффициентов с консоли
void QuadraticEquation::FromConsole(double& a, double& b, double& c)
{
    while (true)
    {
        try
        {
            cout << "Введите коэффициенты квадратного уравнения a, b, c (a != 0):" << endl;
            cout << "a: ";
            // Ввод и проверка коэффициентов
            if (!(cin >> a)) 
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Коэффициент 'a' должен быть числом.");
            }

            if (a == 0) 
            {
                throw invalid_argument("Коэффициент 'a' не может быть равен 0.");
            }

            cout << "b: ";
            if (!(cin >> b)) 
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Коэффициент 'b' должен быть числом.");
            }

            cout << "c: ";
            if (!(cin >> c))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Коэффициент 'c' должен быть числом.");
            }

            break;
        }
        catch (const invalid_argument& e) 
        {
            cerr << "Ошибка: " << e.what() << endl;
        }
    }
}

// Получение коэффициентов из файла
void QuadraticEquation::FromFile(const string& filename, double& a, double& b, double& c) 
{
    ifstream file(filename);
    if (!file)
    {
        throw runtime_error("Не удалось открыть файл: " + filename);
    }
    if(!(file >> a >> b >> c))
    {
        throw runtime_error("Ошибка чтения коэффициентов из файла");
    }
    if (a==0) 
    {
        throw invalid_argument("Коэффициент 'a' не может быть равен 0");
    }
}

// Получение случайных коэффициентов
void QuadraticEquation::Random(double& a, double& b, double& c)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-100,100);

    // Генерация случайного a, не равного 0
    do 
    {
        a = dis(gen);
    } while (a == 0);
    // Генерация остальных коэффициентов
    b = dis(gen);
    c = dis(gen);
}

// Префиксный ++ (увеличивает коэффициенты на 1)
QuadraticEquation& QuadraticEquation::operator++()
{
    ++a;
    ++b;
    ++c;
    return *this;
}

// Постфиксный ++ (возвращает старое значение)
QuadraticEquation QuadraticEquation::operator++(int)
{
    QuadraticEquation temp = *this;
    ++(*this); // Используем префиксный ++
    return temp;
}

// Префиксный -- (уменьшает коэффициенты на 1)
QuadraticEquation& QuadraticEquation::operator--()
{
    --a;
    --b;
    --c;
    return *this;
}

// Постфиксный -- (возвращает старое значение)
QuadraticEquation QuadraticEquation::operator--(int)
{
    QuadraticEquation temp = *this;
    --(*this); // Используем префиксный --
    return temp;
}

// Приведение к double (дискриминант)
QuadraticEquation::operator double() const
{
    return b * b - 4 * a * c;
}

// Явное приведение к bool (есть ли корни?)
QuadraticEquation::operator bool() const
{
    return (b * b - 4 * a * c) >= 0;
}

// Оператор == (сравнивает коэффициенты)
bool QuadraticEquation::operator==(const QuadraticEquation& other) const
{
    return (a == other.a) && (b == other.b) && (c == other.c);
}

// Оператор != (проверяет неравенство коэффициентов)
bool QuadraticEquation::operator!=(const QuadraticEquation& other) const
{
    return !(*this == other); // Используем уже реализованный ==
}

