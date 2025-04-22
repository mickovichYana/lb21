//TreeWork16.Дано число N(> 0) и набор из N чисел.Отсортировать исходный набор чисел,
//создав для него дерево поиска.Вывести указатель P1 на корень полученного дерева, а также
//отсортированный набор чисел(для вывода набора чисел выполнить перебор вершин дерева в
//    инфиксном порядке).

#include "BinaryTreeSearch.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    BinaryTreeSearch tree;
    int choice, n, val;
    cout << "Выберите способ заполнения дерева:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Случайные числа\n";
    cout << "3 - Из файла\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Введите количество чисел: ";
        while (!(cin >> n) || n <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка! Введите целое положительное число: ";
        }
        cout << "Введите числа: ";
        for (int i = 0; i < n; i++)
        {
            while (!(cin >> val))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Ошибка! Введите число: ";
            }
            tree.Insert(val);
        }
        break;
    case 2:
        cout << "Введите количество чисел: ";
        while (!(cin >> n) || n < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка! Введите целое положительное число: ";
        }
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            val = 1 + rand() % 100;
            tree.Insert(val);
        }
        break;
    case 3:
    {
        ifstream file("input.txt");
        if (!file)
        {
            cerr << "Не удалось открыть файл!" << endl;
            return 1;
        }
        while (file >> val)
        {
            tree.Insert(val);
        }
        file.close();
        break;
    }
    default:
        cout << "Неверный выбор.\n";
        return 1;
    }
    cout << "\nУказатель на корень дерева: " << tree.GetRoot()->data << endl;
    tree.PrintOriginalElements();
    tree.PrintSorted();
    tree.PrintTree();
    return 0;
}