#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <limits.h>
#include <vector>

// Definition for a binary tree node.
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

template<typename T>
void print_data(std::vector<T> const & data)
{
  std::cout << "[";
  for (int i=0; i<data.size(); ++i)
    std::cout << data[i] << ' ';
  std::cout << "]\n";


}



template<typename T>
void print_data(std::vector<std::vector<T> > const & data)
{
  std::cout <<"[\n";
  for (int i=0; i<data.size(); ++i)
    print_data(data[i]);
  std::cout <<"]\n";

}


#endif
