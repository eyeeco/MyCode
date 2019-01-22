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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string temp;
        dfs(root, res, temp);
        return res;
    }
    void dfs(TreeNode* root, vector<string>& res, string temp){
        if(root==NULL) { return ;}
        if(!temp.empty()) {
            temp += "->" + to_string(root->val);
        } else{
            temp += to_string(root->val);
        }
        if(root->left==NULL&&root->right==NULL) res.push_back(temp);
        dfs(root->left, res, temp);
        dfs(root->right, res, temp);
    }
};
