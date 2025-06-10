/*номер 1 (задача 6) Спроектировать класс, предусмотрев возможные варианты использования. Реализовать 
определение класса (поля, свойства, конструкторы (не менее трех), перегрузку оператора 
вывода для вывода полей, заданный метод согласно варианту). Протестировать все методы, 
включая конструкторы (не забывайте проверять вводимые пользователем данные 
на корректность).

номер 2 (задача 6) Добавить к реализованному в первом задании классу указанные в варианте перегруженные
операции. Протестировать все операции */

#include "Header.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <limits>
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

// Функция для безопасного ввода коэффициента
double getValidatedDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Ошибка: введите число!" << endl;
        }
        else if (cin.peek() != '\n') {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Ошибка: обнаружены лишние символы после числа!" << endl;
        }
        else {
            cin.ignore(1024, '\n');
            return value;
        }
    }
}

void Constructor() {
    //Конструктор по умолчанию
    QuadraticEquation eq1;
    cout << "1. Конструктор по умолчанию: " << eq1 << endl;
    cout << "   Корни: ";
    auto roots1 = eq1.findRoots();// вызываем метод findRoots()
    if (roots1.empty()) cout << "нет действительных корней";
   // Используем диапазонный цикл for для перебора корней
    for (double root : roots1) {
        if (root == 0) {
            cout << 0 << " ";
        }
        else {
            cout << root << " "; // Форматированный вывод
        }
    }
    cout << endl;
    

    //Конструктор с двумя параметрами
    QuadraticEquation eq2(4,0);
    cout << "2. Конструктор с двумя параметрами (1x^2 + 4x ): " << eq2 << endl;
    cout << "   Корни: ";
    auto roots2 = eq2.findRoots(); // вызываем метод findRoots()
    // Используем диапазонный цикл for для перебора корней
    for (double root : roots2) {
        cout << root << " " ; // Выводим каждый корень и добавляем пробел
    }
    cout << endl;

    //Конструктор с тремя параметрами
    QuadraticEquation eq3(2, -5, -3);
    cout << "3. Конструктор с тремя параметрами (2x^2 - 5x - 3): " << eq3 << endl;
    cout << "   Корни: ";
    auto roots3 = eq3.findRoots(); // вызываем метод findRoots()
    // Используем диапазонный цикл for для перебора корней
    for (double root : roots3) {
        cout << root << " "; // Выводим каждый корень и добавляем пробел
    }
    cout << endl;

    //Попытка создать уравнение с a=0
    cout << "4. Попытка создать уравнение с a=0:" << endl;
    try {
        QuadraticEquation eq4(0, 1, 1);
    }
    catch (const invalid_argument& e) {
        cout << "   Ошибка: " << e.what() << endl;
    }

    // Конструктор копирования
    QuadraticEquation eq5 = eq3; // Используется конструктор копирования
    cout << "5. Конструктор копирования (копирование eq3): " << eq5 << endl;
    cout << "   Корни: ";
    auto roots5 = eq5.findRoots(); // вызываем метод findRoots()
    for (double root : roots5) {
        cout << root << " ";
    }
    cout << endl;
}

// Функция для отображения корней квадратного уравнения
void displayRoots(const vector<double>& roots) 
{
    if (roots.empty())  // Если вектор корней пуст
    {
        cout << "Действительных корней нет." << endl;
    }
    else 
    {
        cout << "Корни: ";
        // Перебираем все найденные корни
        for (double root : roots)
        {
            if (root == -0.0) root = 0.0;  // Убираем -0.0
            cout << root << " ";
        }
        cout << endl;
    }
}


// Функции для демонстрации новых операций
void demoUnaryOperations()
{
    double a, b, c;

    cout << "Введите коэффициенты уравнения (a, b, c):" << endl;
    a = getValidatedDouble("a (не может быть 0): " );
    while (a == 0) {
        cout << "Ошибка: коэффициент a не может быть равен 0!" << endl;
        a = getValidatedDouble("a (не может быть 0): ");
    }
    b = getValidatedDouble("b: ");
    c = getValidatedDouble("c: ");

    QuadraticEquation eq(a, b, c);
    cout << "Исходное уравнение: " << eq << endl;
    ++eq;
    cout << "После ++eq: " << eq << endl;
    QuadraticEquation eq2 = eq--;
    cout << "После eq--: " << eq << endl;
    cout << "Возвращённое значение (старое): " << eq2 << endl;
}

void demoDoubleConversion()
{
    double a, b, c; 
    cout << "Введите коэффициенты уравнения (a, b, c):" << endl;
    a = getValidatedDouble("a (не может быть 0): ");
    while (a == 0) {
        cout << "Ошибка: коэффициент a не может быть равен 0!" << endl;
        a = getValidatedDouble("a (не может быть 0): ");
    }
    b = getValidatedDouble("b: ");
    c = getValidatedDouble("c: ");

    QuadraticEquation eq(a, b, c);
    cout << "Уравнение: " << eq << endl;
    double discriminant = eq;
    cout << "Дискриминант = " << discriminant << endl;
}

void demoBoolConversion()
{
    double a, b, c;
    cout << "Введите коэффициенты уравнения (a, b, c):" << endl;
    a = getValidatedDouble("a (не может быть 0): ");
    while (a == 0) {
        cout << "Ошибка: коэффициент a не может быть равен 0!" << endl;
        a = getValidatedDouble("a (не может быть 0): ");
    }
    b = getValidatedDouble("b: ");
    c = getValidatedDouble("c: ");

    QuadraticEquation eq(a, b, c);
    cout << "Уравнение: " << eq << endl;
    bool hasRoots = static_cast<bool>(eq);
    cout << "Есть ли корни? " << (hasRoots ? "Да" : "Нет") << endl;
}


void demoComparison()
{
    double a1, b1, c1, a2, b2, c2;

    cout << "Введите коэффициенты первого уравнения (a1, b1, c1): ";
    a1 = getValidatedDouble("a1 (не может быть 0): ");
    while (a1 == 0) {
        cout << "Ошибка: коэффициент a1 не может быть равен 0!" << endl;
        a1 = getValidatedDouble("a1 (не может быть 0): ");
    }
    b1 = getValidatedDouble("b1: ");
    c1 = getValidatedDouble("c1: ");

    cout << "Введите коэффициенты второго уравнения (a2, b2, c2): ";
    a2 = getValidatedDouble("a2 (не может быть 0): ");
    while (a2 == 0) {
        cout << "Ошибка: коэффициент a2 не может быть равен 0!" << endl;
        a2 = getValidatedDouble("a2 (не может быть 0): ");
    }
    b2 = getValidatedDouble("b2: ");
    c2 = getValidatedDouble("c2: ");

    QuadraticEquation eq1(a1, b1, c1), eq2(a2, b2, c2);
    cout << "Уравнение 1: " << eq1 << endl;
    cout << "Уравнение 2: " << eq2 << endl;
    cout << "eq1 == eq2: " << (eq1 == eq2 ? "Да" : "Нет") << endl;
    cout << "eq1 != eq2: " << (eq1 != eq2 ? "Да" : "Нет") << endl;
}

void mainEquationMode()
{
    QuadraticEquation currentEquation;
    while (true)
    {
        double a = 0, b = 0, c = 0;
        try
        {
            cout << "\nВыберите способ ввода коэффициентов:\n"
                << "1. Консоль\n"
                << "2. Из файла\n"
                << "3. Случайные значения\n"
                << "4. Копирование уравнения\n"
                << "0. Назад\n"

                << "Ваш выбор: ";
            int choice = getValidatedInt("", 0, 4);
            if (choice == 0) break;

            switch (choice)
            {
            case 1: QuadraticEquation::FromConsole(a, b, c);
                currentEquation = QuadraticEquation(a, b, c); 
                break;
            case 2:
            {
                cout << "Введите имя файла: ";
                string filename;
                cin >> filename;
                QuadraticEquation::FromFile(filename, a, b, c);
                currentEquation = QuadraticEquation(a, b, c);
                break;
            }
            case 3:
            {
                QuadraticEquation::Random(a, b, c);
                cout << "Случайные коэффициенты: a = " << a << ", b = " << b << ", c = " << c << endl;
                currentEquation = QuadraticEquation(a, b, c); 
                break;
            }
            case 4:
            {
                if (currentEquation.getA() == 0 && currentEquation.getB() == 0 && currentEquation.getC() == 0)
                {
                    cout << "Нет уравнения для копирования. Сначала создайте уравнение." << endl;
                    break;
                }
                QuadraticEquation copiedEquation(currentEquation); // Используем конструктор копирования
                cout << "Скопированное уравнение: " << copiedEquation << endl;
                cout << "Корни скопированного уравнения: ";
                displayRoots(copiedEquation.findRoots());

                // Можно работать с копией дальше
                currentEquation = copiedEquation;
                break;
            }
            }

            QuadraticEquation equation(a, b, c);
            cout << "Уравнение: " << equation << endl;
            displayRoots(equation.findRoots());
        }
        catch (const exception& e)
        {
            cerr << "Ошибка: " << e.what() << endl;
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true)
    {
        cout << "1. Решить квадратное уравнение\n"
             << "2. Вывод конструкторов\n"
             << "3. Демонстрация новых операций\n"
           
            << "0. Выход\n"
            << "Ваш выбор: ";

        int choice = getValidatedInt("", 0, 3);
        if (choice == 0) break;

        switch (choice)
        {
        case 1: mainEquationMode(); break;
        case 2: Constructor(); break;
        case 3:
        {
            while (true) {
                cout << "1. Унарные операции (++, --)\n"
                    << "2. Приведение к double (дискриминант)\n"
                    << "3. Приведение к bool (есть ли корни?)\n"
                    << "4. Сравнение уравнений (==, !=)\n"
                    << "0. Назад\n"
                    << "Ваш выбор: ";
                int opChoice = getValidatedInt("", 0, 4);
                if (opChoice == 0) break;
                switch (opChoice)
                {
                case 1: demoUnaryOperations(); break;
                case 2: demoDoubleConversion(); break;
                case 3: demoBoolConversion(); break;
                case 4: demoComparison(); break;
                }
            }
            break;
        }
        }
    }
    return 0;
}