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
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        return max(longPath(root), max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)));
    }
    int longPath(TreeNode* root) {
        if(root==NULL) return 0;
        int len = 0;
        if(root->left&&root->left->val==root->val) len += childPath(root->left) + 1;
        if(root->right&&root->right->val==root->val) len += childPath(root->right) + 1;
        return len;
    }
    int childPath(TreeNode* root) {
        if(root==NULL) return 0;
        int len = 0;
        if(root->left&&root->left->val==root->val) len = max(len, childPath(root->left) + 1);
        if(root->right&&root->right->val==root->val) len = max(len, childPath(root->right) + 1);
        return len;
    }
};
