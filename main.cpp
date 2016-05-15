#include <iostream>
#include <stdlib.h>
#include <vector>
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
class Solution {
public:
    int rob(TreeNode* root) {
        if(NULL==root)
            return 0;

        vector<TreeNode*> vec;

        vec.push_back(root);
        int cur=0;
        int last=1;
        int dept = 0;
        //int rst[2];
        //rst[0] = rst[1] = 0;
        vector<int> data, ds, ns;


        while(cur < vec.size()){
            last = vec.size();
            int sum=0;
            while(cur < last){
                //sum += vec[cur]->val;
                //rst[dept%2] += vec[cur]->val;
                sum += vec[cur]->val;
                cout<<vec[cur]->val<<'\t';
                if(NULL != vec[cur]->left){
                    vec.push_back(vec[cur]->left);
                }
                if(NULL != vec[cur]->right){
                    vec.push_back(vec[cur]->right);
                }
                cur++;
            }
            cout<<endl;
            dept++;
            data.push_back(sum);

        }


        ds.push_back(data[0]);
        ns.push_back(0);

        for(int i=1; i<data.size(); i++){
                ds.push_back(ns[i-1]+data[i]);
                ns.push_back(ns[i-1]>ds[i-1]?ns[i-1]:ds[i-1]);

        }
        /*
        while(data.size()>0){
            cout<<data.back()<<endl;
            data.pop_back();
        }*/
        //cout<<"dept0: "<<rst[0]<<endl;
        //cout<<"dept1: "<<rst[1]<<endl;
        return ds.back()>ns.back()?ds.back():ns.back();



    }
};





int main()
{
    Solution solt;
#if 0
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    //root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
#endif // 0

#if 0
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

#endif // 1

#if 0
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

#endif // 1

#if 1
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(3);
#endif // 1
    cout<<solt.rob(root);

    //FIXME: need delete memory alloct
    return 0;
}
