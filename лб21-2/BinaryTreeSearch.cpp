#include "BinaryTreeSearch.h"
#include <iostream>
#include <fstream>
using namespace std;

BinaryTreeSearch::BinaryTreeSearch() : root(nullptr) {}
TreeNode* BinaryTreeSearch::InsertRec(TreeNode* node, int val)// Рекурсивная функция для вставки узла
{
    if (node == nullptr) return new TreeNode(val);
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
void BinaryTreeSearch::Insert(int val)// Вставка значения в дерево
{
    root = InsertRec(root, val);
    originalElements.push_back(val);
}
void BinaryTreeSearch::InOrderRec(TreeNode* node) // Инфиксный обход (для вывода отсортированных чисел)
{
    if (node == nullptr) return;
    InOrderRec(node->left);
    cout << node->data << " ";
    InOrderRec(node->right);
}
void BinaryTreeSearch::PrintSorted()// Вывод отсортированных чисел
{
    cout << "Отсортированные числа: ";
    InOrderRec(root);
    cout << endl;
}
void BinaryTreeSearch::PrintRec(TreeNode* node, int level)// Вывод дерева 
{
    if (node == nullptr) return;
    PrintRec(node->right, level + 1);
    for (int i = 0; i < level; i++) cout << "    ";
    cout << node->data << endl;
    PrintRec(node->left, level + 1);
}
void BinaryTreeSearch::PrintTree() // Вывод структуры дерева
{
    cout << "Структура дерева:\n";
    PrintRec(root);  
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
TreeNode* BinaryTreeSearch::GetRoot() // Получить указатель на корень
{
    return root;
}