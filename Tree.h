#pragma once
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <string>

class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val);
};

class Tree
{
private:
    TreeNode* root;
    std::vector<int> originalElements;

    TreeNode* InsertRec(TreeNode* node, int val);
    void PrintRec(TreeNode* node, int space);
public:
    Tree();
    void Insert(int val);
    int FindMin();
    void Print();
    void PrintOriginalElements();
    void Keyboard();
    void Random(int count, int minVal, int maxVal);
    void File(const std::string& filename);
};

#endif