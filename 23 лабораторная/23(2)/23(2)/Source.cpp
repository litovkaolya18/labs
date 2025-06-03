#include "Header.h"

// Вставка узла в бинарное дерево
void BinaryTree::insert(int v) 
{ 
    Node* newNode = new Node(v);
    //проверка на пустое дерево
    if (!root) 
    {
        root = newNode; //новый узел становится корнем
        return;
    }

    Node* current = root; //для перемещения
    Node* parent = nullptr; //хранит предыдущий узел  

    while (true) 
    {    //Запоминаем текущий узел как родителя
        parent = current; 
        if (v < current->val) 
        {   //проверка левого потомка
            current = current->left;
            if (!current) 
            {   //вставка нового узла слево
                parent->left = newNode;
                return;
            }
        }
        else //значение больше или равно
        {   //идём вправо
            current = current->right;
            if (!current) 
            {
                parent->right = newNode;
                return;
            }
        }
    }
}

// Вводит все узлы на границе дерева против часовой стрелки
void BinaryTree::printLeaves(Node* node, vector<int>& leaves)
{
    if (!node) return;

    // Если это листовой узел, добавляем его в список
    if (!node->left && !node->right) 
    {
        leaves.push_back(node->val);
    }

    // Рекурсивный вызов для левого и правого поддерева
    printLeaves(node->left, leaves);
    printLeaves(node->right, leaves);
}
//сборка значений узлов слево на границе дерева
void BinaryTree::printLeftBoundary(Node* node, vector<int>& boundary) 
{
    if (!node) return;

    // Проверка на наличие левого потомка
    if (node->left) 
    {
        boundary.push_back(node->val); //добавл.знач тек.узла
        printLeftBoundary(node->left, boundary);
    } //на наличие правого потомка
    else if (node->right) 
    {
        boundary.push_back(node->val);
        printLeftBoundary(node->right, boundary);
    }
}

void BinaryTree::printRightBoundary(Node* node, vector<int>& boundary) 
{
    if (!node) return;

    // Проверка на наличие правого потомка
    if (node->right) 
    {
        printRightBoundary(node->right, boundary);
        boundary.push_back(node->val);
    } //левого
    else if (node->left) 
    {
        printRightBoundary(node->left, boundary);
        boundary.push_back(node->val);
    }
}
//вывод границ в правильном порядке
void BinaryTree::printBoundary() 
{
    vector<int> boundary;

    if (root) 
    {
        boundary.push_back(root->val); // Добавляем корень первым

        printLeftBoundary(root->left, boundary);

        // Листовые узлы
        vector<int> leaves;
        printLeaves(root, leaves);
        boundary.insert(boundary.end(), leaves.begin(), leaves.end());

        printRightBoundary(root->right, boundary);

        // Вывод границы
        for (int val : boundary) 
        {
            cout << val << " ";
        }

        cout << endl;
    }
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