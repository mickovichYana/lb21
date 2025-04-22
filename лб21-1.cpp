//TreeWork7.Дано дерево поиска и указатель корень дерева P1.Необходимо вывести
//минимальное значение в дереве.Решение должно иметь сложность по времени исполнения T(n)
//= O(log n), где n - число вершин в дереве.

#include <iostream>
#include "Tree.h"
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    Tree tree;
    int choice, val,n;
    cout << "Выберите способ заполнения дерева:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Случайными числами\n";
    cout << "3 - Из файла\n";
    cin >> choice;
    switch (choice) 
    {
    case 1:
        tree.Keyboard();
        break;
    case 2:
        cout << "Введите количество чисел: ";
        cin >> n;
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            val = 1 + rand() % 100;
            tree.Insert(val);
        }
        break;
    case 3:
        tree.File("input.txt");
        break;
    default:
        cout << "Неверный выбор.\n";
        return 1;
    }
    tree.PrintOriginalElements();
    cout << "\nДерево:\n";
    tree.Print();
    cout << "\nМинимальное значение в дереве: " << tree.FindMin() << endl;
    return 0;
}