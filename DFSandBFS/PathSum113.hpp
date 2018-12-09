/*113. Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum 
equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]*/


class PathSum113 {

public:

  vector<vector<int> > findSum(TreeNode* root, int sum) {
    // leaf node
    if (root->left == NULL && root->right == NULL) {
       if (sum == root->val) return {{root->val}};
       else return {};
    }
    vector<vector<int> > res = {};

    if (root->left != NULL) {
       vector<vector<int> > path = findSum(root->left, sum - root->val);
      if (!path.empty()) {
        for (int i=0; i<path.size(); ++i)
          path[i].insert(path[i].begin(), root->val);
        res = path;  
      }
    }

    if (root->right != NULL) {
       vector<vector<int> > path = findSum(root->right, sum - root->val);
      if (!path.empty()) {
        for (int i=0; i<path.size(); ++i)
          path[i].insert(path[i].begin(), root->val);
        res.insert(res.end(), path.begin(), path.end());
      }
    }

    return res;

  }


  vector<vector<int>> solve(TreeNode* root, int sum) {
    if (root == NULL) return {};
    return findSum(root, sum);
  }



  void test()
  {
    vector<int> treeVec;
    vector<vector<int> > paths;
    int sum;

    treeVec = {5, 4, 8, 11, INT_MAX, 13, 4, 7, 2, INT_MAX, INT_MAX, 5, 1};
    sum = 22;
    TreeNode* root = createTreeLevelOrder(treeVec);
    cout << "input tree is : \n";
    printTreeLevelOrder(root);
    paths = solve(root, sum);
    cout << "all paths for sum " << sum << " is:\n";
    print_data(paths);
  }


};
