/*TreeFun2.Преобразовать двусвязный список в бинарное дерево поиска без использования
дополнительной памяти(создания новых объектов).Корнем дерева должен стать элемент
списка, находящийся в его середине, а само дерево должно иметь наименьшую возможную
высоту.При преобразовании поля left и right узлов бинарного дерева рассматриваются
эквивалентными полям prev и next узлов двусвязного списка.Вывести исходный список и
получившееся дерево.*/

#include "Header.h"
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Ввод элементов
    vector<int> vals;
    int x;
    cout << "Введите элементы списка через пробел, завершите (-1) после для завершения:\n";
    while (true) 
    {
        if (!(cin >> x)) 
        {
            cout << "Ошибка ввода!\n";
            break;
        }
        if (x == -1) break;
        vals.push_back(x);
    }

    if (vals.empty())
    {
        cout << "Пустой список.\n";
        return 0;
    }

    // Сортировка входных данных, чтобы создать корректное BST
    sort(vals.begin(), vals.end());

    // Вывод отсортированного списка
    cout << "\nОтсортированный список:\n";
    for (int val : vals) 
    {
        cout << val << " ";
    }
    cout << endl;

    Node* head = createList(vals);
    Node* root = listToBST(head);

    cout << "\nБалансированное бинарное дерево:\n";
    printTree(root);

    // Очистка памяти
    freeTree(root);
    return 0;
}








//#include <iostream>
//#include <windows.h>
//#include <algorithm> // Для функции sort
//#include <vector>
//#include <string>
//using namespace std;
//
//class Node 
//{
//public:
//    int val;//хранит значение узла(элемент списка)
//    Node* prev; // левый поддерево
//    Node* next; // правый поддерево
//
//    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
//};
//
////Создаем двусвязный список из вектора
//Node* createList(const vector<int>& vals) 
//{
//    Node* head = nullptr; //ссылка на первый узел списка
//    Node* tail = nullptr; //ссылка на последний узел списка
//    for (int v : vals) 
//    {
//        Node* node = new Node(v);
//        if (!head)
//            head = tail = node;
//        else 
//        {
//            tail->next = node; //: Устанавливаем указатель next последнего узла (tail) на новый узел.
//            node->prev = tail;
//            tail = node;  //Обновляем указатель tail, чтобы он указывал на новый узел.
//        }
//    }
//    return head;
//}
//
////вычисления длины двусвязного списка
//int getLength(Node* head) {
//    int len = 0; //для хранения длины
//    while (head) {
//        len++;
//        head = head->next;//переход к следующему узлу
//    }
//    return len;
//}
//// получение узла 
//Node* getNodeAt(Node* head, int index) {
//    if (index < 0) return nullptr; // Проверка на отрицательный индекс
//    for (int i = 0; i < index && head; i++) {
//        //На каждой итерации переменная head обновляется на следующий узел
//        head = head->next;
//    }
//    return head;
//}
////преобразует связный список в сбалансированное двоичное дерево поиска(BST)
//Node* listToBST(Node* head) {
//    if (!head) return nullptr;
//
//    int len = getLength(head);
//    if (len == 1) {
//        head->prev = nullptr;
//        head->next = nullptr;
//        return head;
//    }
//    //Нахождение среднего узла
//    int midIdx = len / 2;
//    Node* mid = getNodeAt(head, midIdx);//возвращает указатель на узел с этим индексом.
//
//    //Обработка указателей соседних узлов
//    if (mid->prev) mid->prev->next = nullptr;
//    if (mid->next) mid->next->prev = nullptr;
//
//    //Разделение списка на две части
//    Node* leftHead = (head == mid) ? nullptr : head;
//    Node* rightHead = mid->next;
//
//    //Обнуление указателей среднего узла
//    mid->prev = nullptr;
//    mid->next = nullptr;
//
//    //Рекурсивные вызовы для построения поддеревьев
//    mid->prev = listToBST(leftHead);
//    mid->next = listToBST(rightHead);
//
//    return mid;//Возврат корня поддерева
//}
//
//// Вывод дерева с линиями '/' и '\'
//void printTree(Node* root, string prefix = "", bool isLeft = true) {
//    if (!root) return;
//    // Рекурсивно выводим правое поддерево
//    if (root->next)
//        printTree(root->next, prefix + (isLeft ? "|   " : "    "), false);
//
//    cout << prefix;
//    if (isLeft)
//        cout << "\\--";  // левое
//    else
//        cout << "/--";   // правое
//    cout << root->val << "\n";
//
//    // Выводим левое поддерево
//    if (root->prev)
//        printTree(root->prev, prefix + (isLeft ? "    " : "|   "), true);
//}
//
//// Освобождение памяти двоичного дерева
//void freeTree(Node* root) {
//    if (!root) return;
//    freeTree(root->prev);
//    freeTree(root->next);
//    delete root;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    // Ввод элементов
//    vector<int> vals;
//    int x;
//    cout << "Введите элементы списка через пробел, завершите (-1) после для завершения:\n";
//    while (true) {
//        if (!(cin >> x)) {
//            cout << "Ошибка ввода!\n";
//            break;
//        }
//        if (x == -1) break;
//        vals.push_back(x);
//    }
//
//    if (vals.empty()) {
//        cout << "Пустой список.\n";
//        return 0;
//    }
//
//    // Сортировка входных данных, чтобы создать корректное BST
//    sort(vals.begin(), vals.end());
//    // Вывод отсортированного списка
//    cout << "\nОтсортированный список:\n";
//    for (int val : vals) {
//        cout << val << " ";
//    }
//    cout << endl;
//
//    Node* head = createList(vals);
//    Node* root = listToBST(head);
//
//    cout << "\nБалансированное бинарное дерево:\n";
//    printTree(root);
//
//
//    // Очистка памяти
//    freeTree(root);
//    // (можно реализовать функцию освобождения, чтобы не лагать в памяти)
//    return 0;
//}
