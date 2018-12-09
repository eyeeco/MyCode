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
    int rootPath(TreeNode* root,int& num){
        if(root){
            int left = rootPath(root->left,num);
            int right = rootPath(root->right,num);
            num = max(num,max(left,0)+max(right,0)+root->val);
            return max(0,max(left,right))+root->val;
        }
        return 0;
    }
    int maxPathSum(TreeNode* root) {
        if(root){
            int num = INT_MIN;
            rootPath(root,num);
            return num;
        }
        else
            return 0;
    }
};
