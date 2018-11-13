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
    int temp = INT_MIN;
    int flag = 0;
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        if(!isValidBST(root->left)) return false;
        if(flag&&root->val<=temp){
            return false;
        }else{
            temp = root->val;
            flag = 1;
        }
        if(!isValidBST(root->right)) return false;
        return true;
    }
};
