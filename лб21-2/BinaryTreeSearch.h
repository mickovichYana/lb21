#pragma once
#ifndef BINARYTREESEARCH_H
#define BINARYTREESEARCH_H
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
class BinaryTreeSearch
{
private:
    TreeNode* root;
    std::vector<int> originalElements;
    TreeNode* InsertRec(TreeNode* node, int val);
    void InOrderRec(TreeNode* node);
    void PrintRec(TreeNode* node, int level = 0);
public:
    BinaryTreeSearch();
    void Insert(int val);
    void PrintSorted();
    void PrintTree();
    void PrintOriginalElements();
    TreeNode* GetRoot();
};
#endif