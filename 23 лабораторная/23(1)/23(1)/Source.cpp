#include "Header.h"

// —оздаем двусв€зный список из вектора
Node* createList(const vector<int>& vals)
{
    Node* head = nullptr; // ссылка на первый узел списка
    Node* tail = nullptr; // ссылка на последний узел списка
    for (int v : vals) 
    {
        //создание нового узла с текущим значением
        Node* node = new Node(v);
        if (!head)
            head = tail = node;
        else 
        {
            tail->next = node; // предыдущий узел ссылаетс€ на новый через next
            node->prev = tail; // обновл€ем указатель prev на новый узел
            tail = node;       // обновл€ем хвост чтобы указывать на последний узел
        }
    }
    return head;
}

// вычислени€ длины двусв€зного списка
int getLength(Node* head) 
{
    int len = 0; // дл€ хранени€ длины
    while (head) 
    {
        len++;
        head = head->next; // переход к следующему узлу
    }
    return len;
}

// получение узла по индексу
Node* getNodeAt(Node* head, int index) 
{
    if (index < 0) return nullptr;
    for (int i = 0; i < index && head; i++) 
    {
        head = head->next; // на каждой итерации переменна€ head обновл€етс€ на следующий узел
    }
    return head;
}

// преобразует св€зный список в сбалансированное двоичное дерево поиска(BST)
Node* listToBST(Node* head) 
{
    if (!head) return nullptr;

    int len = getLength(head);//получаем длину списка
    if (len == 1) 
    { 
        head->prev = nullptr;
        head->next = nullptr;
        return head;
    }

    // Ќахождение среднего узла
    int midIdx = len / 2;
    Node* mid = getNodeAt(head, midIdx); // возвращает указатель на узел с этим индексом

    // ќтключение соседних узлов
    if (mid->prev) mid->prev->next = nullptr; // отключаем левую часть
    if (mid->next) mid->next->prev = nullptr; // отключаем правую часть

    // –азделение списка на две части
    Node* leftHead = (head == mid) ? nullptr : head; // Ћевое поддерево
    Node* rightHead = mid->next; // ѕравое поддерево

    // ќбнуление указателей среднего узла
    mid->prev = nullptr;
    mid->next = nullptr;

    // –екурсивные вызовы дл€ построени€ поддеревьев
    mid->prev = listToBST(leftHead);
    mid->next = listToBST(rightHead);

    return mid; // ¬озврат корн€ поддерева
}

// ¬ывод дерева с лини€ми '/' и '\'
void printTree(Node* root, string prefix, bool isLeft) {
    if (!root) return;

    // ¬ыводим правое поддерево
    if (root->next)
        printTree(root->next, prefix + (isLeft ? "|   " : "    "), false);

    // ¬ыводим текущий узел
    cout << prefix;
    if (isLeft)
        cout << "\\--";  // левое поддерево
    else
        cout << "/--";   // правое поддерево
    cout << root->val << "\n"; // ¬ывод значени€ узла

    // ¬ыводим левое поддерево
    if (root->prev)
        printTree(root->prev, prefix + (isLeft ? "    " : "|   "), true);
}

// ќсвобождение пам€ти двоичного дерева
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->prev);
    freeTree(root->next);
    delete root;
}
