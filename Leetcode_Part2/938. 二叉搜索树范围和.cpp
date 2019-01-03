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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL) return 0;
        if (root->val>=L && root->val<=R) {
           return root->val+rangeSumBST(root->left,L,root->val)+rangeSumBST(root->right,root->val,R);
        }else {
            return rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
        }
    }
};s
