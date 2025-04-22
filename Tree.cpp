#include "Tree.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <clocale>
using namespace std;

TreeNode::TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
Tree::Tree() : root(nullptr) {}
TreeNode* Tree::InsertRec(TreeNode* node, int val)// Рекурсивная функция для вставки узла
{
    if (node == nullptr)
    {
        return new TreeNode(val);
    }
    if (val < node->data)
    {
        node->left = InsertRec(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = InsertRec(node->right, val);
    }
    return node;
}
void Tree::PrintRec(TreeNode* node, int space)// Рекурсивная функция для печати дерева 
{
    if (node == nullptr) return;
    space += 5;
    PrintRec(node->right, space);
    cout << endl;
    for (int i = 5; i < space; i++)
    {
        cout << " ";
    }
    cout << node->data << "\n";
    PrintRec(node->left, space);
}
void Tree::Insert(int val)// Функция для вставки значения в дерево
{
    root = InsertRec(root, val);
    originalElements.push_back(val);
}
int Tree::FindMin()// Функция для поиска минимального значения 
{
    if (root == nullptr)
    {
        cerr << "Дерево пустое!" << endl;
        return 0;
    }
    TreeNode* current = root;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current->data;
}
void Tree::Print()// Функция для печати дерева
{
    PrintRec(root, 0);
}
void Tree::PrintOriginalElements()// Функция для вывода исходных элементов
{
    cout << "Исходные элементы: ";
    for (int elem : originalElements)
    {
        cout << elem << " ";
    }
    cout << endl;
}
void Tree::Keyboard()//Функция для заполнения дерева с клавиатуры
{
    cout << "Введите количество элементов: ";
    int n;
    while (true)
    {
        while (!(cin >> n))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка! Введите целое число: ";
        }

        if (n > 0)
        {
            break;
        }
        else
        {
            cout << "Ошибка! Количество элементов не может быть отрицательным. Повторите ввод: ";
        }
    }

    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        while (!(cin >> val))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка! Введите целое число: ";
        }
        Insert(val);
    }
}
void Tree::File(const std::string& filename)//Функция для заполнения дерева из файла
{
    ifstream file(filename);
    if (!file) {
        cerr << "Не удалось открыть файл " << filename << endl;
        return;
    }
    int val;
    while (file >> val)
    {
        Insert(val);
    }
    file.close();
}