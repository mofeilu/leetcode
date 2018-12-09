
/*513. Find Bottom Left Tree Value
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
*/
class FindBottomLeftTreeValue513 {

public:
  /*
  idea: use DFS, but return both value and depth
  */
  void DFS(TreeNode* root, int & val, int & depth) {
    if (root->left == NULL && root->right == NULL) {
      val = root->val; depth = 0;
      return;
    }
    depth = 0; val = 0;
    if (root->left != NULL) {
      int depthLeft;
      DFS(root->left, val, depthLeft);
      depth = max(depth, depthLeft + 1);
    }

    if (root->right != NULL) {
      int depthRight; int valRight;
      DFS(root->right, valRight, depthRight);
      if (depthRight + 1 > depth) {
        val = valRight;
        depth = depthRight + 1;
      }
    }
  }

  int solve(TreeNode* root) {
    int val, depth;
    DFS(root,val, depth);
    return val;
  }

  void test()
  {
    vector<int> treeVec;
    treeVec = {1,  2, 3,  4, INT_MAX, 5, 6, INT_MAX, INT_MAX,  7, INT_MAX, INT_MAX, INT_MAX};
    TreeNode* root = createTreeLevelOrder(treeVec);
    cout << "input tree is : \n";
    printTreeLevelOrder(root);
    cout << "bottom left val is " << solve(root) << endl;
  }

};
