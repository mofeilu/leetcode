#include "utils.hpp"


TreeNode* createTree(std::vector<std::vector<int> > const & vals)
{
    TreeNode* root =NULL;
    if (vals.size() == 0) return root;
    if (vals[0].size() == 0) return root;
    if (vals[0][0] == INT_MAX) return root;  // this means it's null
    root = new TreeNode(vals[0][0]);
    std::vector<TreeNode* > lastLev(1, root);
    std::vector<TreeNode* > currLev;  
    //std::cout<<root->val<<std::endl;
    for (int i=1; i<vals.size(); ++i) {
      currLev.clear();
      int count = 0; 
      for (int n=0; n<lastLev.size(); ++n) {
        if (count >= vals[i].size())
           lastLev[n]->left = NULL; 
        else if (vals[i][count] == INT_MAX)
           lastLev[n]->left = NULL;
        else {
          lastLev[n]->left = new TreeNode(vals[i][count]);
          currLev.push_back(lastLev[n]->left);
        }
        count++;

        if (count >= vals[i].size())
          lastLev[n]->right = NULL;  
        else if (vals[i][count] == INT_MAX)
          lastLev[n]->right = NULL;
        else {
          lastLev[n]->right = new TreeNode(vals[i][count]);
          currLev.push_back(lastLev[n]->right);
        }
        count++;

      }
             // show current level
             /*for (int j=0; j<currLev.size(); ++j) 
                if (currLev[j] != NULL)
                  std::cout << currLev[j]->val << ' ';*/
      std::cout<<std::endl;   
      lastLev.clear();
      lastLev = currLev;
    }

  return root;
       
    
 }
      

 void printTreeLevelOrder(TreeNode* root)
 {
   std::vector<TreeNode* > currLev;
   currLev.push_back(root);
   std::vector<TreeNode* > nextLev;
   while (!currLev.empty()) {
     nextLev.clear();
     // from the end go backward, find the first non NULL pos 
     int endPos = (int)currLev.size()-1;
     for (; endPos >=0; --endPos)
       if (currLev[endPos] != NULL)
          break;
     

     for (int i=0; i<=endPos; ++i) {
       if (currLev[i] != NULL) {
         std::cout << currLev[i]->val << ' ';
         nextLev.push_back(currLev[i]->left);
         nextLev.push_back(currLev[i]->right);
       } else {
         std::cout << "n" << ' ';
       }
     }
     std::cout << std::endl;
     currLev.clear();
     currLev = nextLev;

    }
    
  }



TreeNode* createTreeLevelOrder(std::vector<int> const & vals)
{
  TreeNode* root = NULL;
  if (vals.empty()) return root;

  root = new TreeNode(vals[0]);
  std::vector<TreeNode* > lastLev(1, root);
  std::vector<TreeNode* > nextLev;  

  int count = 1;
  while (count<vals.size()) {
    nextLev.clear(); 
    for (int i=0; i<lastLev.size(); ++i) {
      if (count < vals.size()) {
        if (lastLev[i] != NULL) {
           lastLev[i]->left = (vals[count] == INT_MAX) ? NULL : new TreeNode(vals[count]);
           nextLev.push_back(lastLev[i]->left);
           count++;

           if (count < vals.size()) {
             lastLev[i]->right = (vals[count] == INT_MAX) ? NULL : new TreeNode(vals[count]);
             nextLev.push_back(lastLev[i]->right);
             count++; 
           } else {
            lastLev[i]->right = NULL;
           }
        }

      } else {
        if (lastLev[i] != NULL) {
          lastLev[i]->left = NULL;
          lastLev[i]->right = NULL;
        }

      }
    }

    lastLev.clear();
    lastLev = nextLev;

  }

  return root;

}



