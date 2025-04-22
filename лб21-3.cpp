//TreeWork17.Дано дерево поиска и указатель корень дерева P1.Необходимо вывести второе
//минимальное значение в дереве.Решение должно иметь сложность по времени исполнения T(n)
//= O(log n), где n - число вершин в дереве.

#include "BinaryTreeSearch.h"
#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    BinaryTreeSearch tree;
    int choice, val,n;
    cout << "Выберите способ заполнения дерева:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Случайные числа\n";
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
        cout << "Неверный выбор" << endl;
        return 1;
    }
    int secondMin = tree.FindSecondMin(); 
    if (secondMin == -1) 
    {
        cout << "В дереве меньше двух элементов" << endl;
    }
    else 
    {
        tree.PrintOriginalElements();
        tree.Print();
        cout << "Второй минимальный элемент: " << secondMin << endl;
    }
    return 0;
}