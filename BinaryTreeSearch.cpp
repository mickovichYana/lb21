#include "BinaryTreeSearch.h"
#include <iostream>
#include <fstream>
using namespace std;

BinaryTreeSearch::BinaryTreeSearch() : root(nullptr) {}
TreeNode* BinaryTreeSearch::InsertRec(TreeNode* node, int val)// Рекурсивная функция для печати дерева 
{
    if (!node) return new TreeNode(val);
    if (val < node->val)
    {
        node->left = InsertRec(node->left, val);
    }
    else if (val > node->val)
    {
        node->right = InsertRec(node->right, val);
    }
    return node;
}
void BinaryTreeSearch::PrintTree(TreeNode* node, int level)// Вывод структуры дерева
{
    if (!node) return;
    PrintTree(node->right, level + 1);
    for (int i = 0; i < level; i++) cout << "   ";
    cout << node->val << endl;
    PrintTree(node->left, level + 1);
}
void BinaryTreeSearch::SecondMin(TreeNode* node, int& min1, int& min2)//Рекурсивный поиск второго минимального элемента
{
    if (!node) return;

    if (node->val < min1)
    {
        min2 = min1;
        min1 = node->val;
    }
    else if (node->val < min2 && node->val != min1)
    {
        min2 = node->val;
    }

    SecondMin(node->left, min1, min2);

    if (min2 == INT_MAX)
    {
        SecondMin(node->right, min1, min2);
    }
}
void BinaryTreeSearch::Insert(int val)// Функция для вставки значения в дерево
{
    root = InsertRec(root, val);
    originalElements.push_back(val);
}
void BinaryTreeSearch::Print()// Функция для печати дерева
{
    cout << "Дерево:" << endl;
    PrintTree(root, 0);
}
void BinaryTreeSearch::PrintOriginalElements()// Функция для вывода исходных элементов
{
    cout << "Исходные элементы: ";
    for (int elem : originalElements)
    {
        cout << elem << " ";
    }
    cout << endl;
}
int BinaryTreeSearch::FindSecondMin()// Функция для поиска второго минимального элемента
{
    if (!root || (!root->left && !root->right)) 
    {
        return -1; 
    }
    TreeNode* current = root;
    while (current->left) 
    {
        current = current->left;
    }
    if (current->right) 
    {
        TreeNode* temp = current->right;
        while (temp->left)
        {
            temp = temp->left; 
        }
        return temp->val;
    }
    else 
    {
        TreeNode* secondMin = root;
        TreeNode* minNode = current;
        while (secondMin->left != minNode && secondMin->right != minNode) 
        {
            if (minNode->val < secondMin->val) 
            {
                secondMin = secondMin->left;
            }
            else 
            {
                secondMin = secondMin->right;
            }
        }
        return secondMin->val;
    }
}
void BinaryTreeSearch::File(const string& filename)//Функция для заполнения дерева из файла
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Не удалось открыть файл!" << endl;
        return;
    }
    int val;
    while (file >> val)
    {
        Insert(val);
    }
    file.close();
}
void BinaryTreeSearch::Keyboard()//Функция для заполнения дерева с клавиатуры
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

        if (n >= 0)
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