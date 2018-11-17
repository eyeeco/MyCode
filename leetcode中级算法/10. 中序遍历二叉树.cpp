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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> con;
        vector<int> res;
        while(root){
            con.push(root);
            root = root->left;
        }
        while(!con.empty()){
            TreeNode* temp = con.top();
            res.push_back(temp->val);
            con.pop();
            temp = temp->right;
            while(temp){
                con.push(temp);
                temp = temp->left;
            }
        }
        return res;
    }
};
