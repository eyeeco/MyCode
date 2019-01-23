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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1, s2;
        getchild(root1, s1);
        getchild(root2, s2);
        return s1==s2;
    }
    void getchild(TreeNode* root, string& str) {
        if(root==NULL) return ;
        if(root->left==NULL&&root->right==NULL) str+= to_string(root->val);
        getchild(root->left, str);
        getchild(root->right, str);
    }
};
