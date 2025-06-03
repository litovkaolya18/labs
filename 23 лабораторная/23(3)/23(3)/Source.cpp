#include <random>
#include "Header.h"
using namespace std;

BinaryTree::Node::Node(int value) 
    : val(value), left(nullptr), right(nullptr), parent(nullptr), burnt(false) {}

BinaryTree::BinaryTree() : root(nullptr) {}

//строим дерево 
BinaryTree::Node* BinaryTree::insertRec(Node* node, int value, Node* parent) 
{
    if (!node) 
    {
        Node* newNode = new Node(value);
        newNode->parent = parent; // Устанавливаем родителя
        return newNode;
    }
    if (value < node->val)
    {
        node->left = insertRec(node->left, value, node);
    }
    else 
    {
        node->right = insertRec(node->right, value, node);
    }
    return node;
}
// Вставка узла в бинарное дерево
void BinaryTree::insert(int value)
{
    root = insertRec(root, value, nullptr);
}


// Вывод дерева боком
void BinaryTree::printTree(Node* node, const string& prefix, bool isLeft) 
{
    if (!node) return;

    // Выводим правое поддерево
    if (node->right)
        printTree(node->right, prefix + (isLeft ? "|   " : "    "), false);

    // Выводим текущий узел
    cout << prefix;
    if (isLeft)
        cout << "\\--";  // левое поддерево
    else
        cout << "/--";   // правое поддерево
    cout << node->val << "\n"; // Вывод значения узла

    // Выводим левое поддерево
    if (node->left)
        printTree(node->left, prefix + (isLeft ? "    " : "|   "), true);
}

void BinaryTree::printTree(Node* node) 
{
    printTree(node, "", false); // Вызов с пустым префиксом и для правого поддерева
}

void  BinaryTree::print() 
{
    if (!root) 
    {
        cout << "Дерево пустое!" << endl;
        return;
    }
    printTree(root);
}
// Вывод узлов с горением
void BinaryTree::burnFire(Node* start)
{
    if (!start) 
    {
        cout << "Ошибка: Начальный узел равен нулю!" << endl;
        return;
    }
    queue<Node*> q;
    q.push(start);
  
    while (!q.empty()) 
    {
        Node* current = q.front();
        q.pop();
        // Если узел еще не сгорел
        if (!current->burnt) 
        {
            cout << "Горит узел со значением: " << current->val << endl; // Выводим узел, который горит
            current->burnt = true; // Устанавливаем флаг сгорания

            // Добавляем детей
            if (current->left) 
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }

            // Добавляем родителя
            if (current->parent) 
            {
                q.push(current->parent);
            }
        }
    }
}
BinaryTree::Node* BinaryTree::findNode(int value)
{
    queue<Node*> q;
    if (!root) return nullptr;
    q.push(root);

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        if (current->val == value) 
        {
            return current; // Возвращаем найденный узел
        }
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return nullptr; // Если узел не найден
}

