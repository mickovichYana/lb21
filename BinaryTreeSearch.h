#pragma once
#ifndef BINARYTREESEARCH_H
#define BINARYTREESEARCH_H

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
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class BinaryTreeSearch
{
private:
    TreeNode* root;
    std::vector<int> originalElements;

    TreeNode* InsertRec(TreeNode* node, int val);
    void PrintTree(TreeNode* node, int level);
    void SecondMin(TreeNode* node, int& min1, int& min2);

public:
    BinaryTreeSearch();
    void Insert(int val);
    void Print();
    void PrintOriginalElements();
    int FindSecondMin();
    void File(const std::string& filename);
    void Keyboard();
};

#endif