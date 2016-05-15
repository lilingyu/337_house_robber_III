#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution{

 private:

     vector<int> robSub(TreeNode* root){
        if(NULL == root){
            return vector<int>(2,0);
        }

        vector<int> left = robSub(root->left);
        vector<int> right = robSub(root->right);

        printf("root:\t%d\n", root->val);
        printf("left:\t%d\t%d\n", left[0], left[1]);
        printf("right:\t%d\t%d\n\n", right[0], right[1]);

        vector<int> res(2,0);

        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];

        return res;
     }



 public:
    int rob(TreeNode* root){
        vector<int> result = robSub(root);

        return max(result[0], result[1]);
    }



 };


 int main()
 {
     Solution solt;
#if 0
     /*
case 0:
    4
    /\
   1 NULL
   /\
  2 NULL
 /
3

     */
     TreeNode* root = new TreeNode(4);
     root->left = new TreeNode(1);
     root->left->left = new TreeNode(2);
     root->left->left->left = new TreeNode(3);
#endif // 0

#if 1

/*
case 1:
  2
  /\
 1 3
  \
   4
*/
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
#endif // 1

     cout<<solt.rob(root);

     return 0;
 }
