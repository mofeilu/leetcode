#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <limits.h>

struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ~TreeNode() {
   if (left != NULL) delete left;
   if (right != NULL) delete right;
 }
};

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};


TreeNode* createTree(std::vector<std::vector<int> > const & vals);
void printTreeLevelOrder(TreeNode* root);
TreeNode* createTreeLevelOrder(std::vector<int> const & vals);


void inline print_data(int x)
{
  std::cout << "[" << x << "]\n"; 
}

template <typename T1, typename T2>
std::ostream & operator << (std::ostream & os, std::pair<T1, T2> t)
{
  os << "( " << t.first << ' ' << t.second <<" )";
  return os;
}

template <typename T>
void print_data(std::vector<T> const & x)
{
   std::cout << "[" << ' ';
    for (size_t i = 0; i<x.size(); ++i)
        std::cout << x[i] << ' ';
    std::cout << "]" << std::endl;
}

template <typename T>
void print_data(std::vector<std::vector<T> > const & x) 
{
  std::cout << "[" << ' ';
    for (size_t i = 0; i<x.size(); ++i)
        print_data(x[i]);
  std::cout << "]" << std::endl;
}




#endif
