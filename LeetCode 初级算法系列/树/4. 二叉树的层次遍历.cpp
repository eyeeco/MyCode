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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> con;
        vector<vector<int>> res;
        vector<int> cp;
        if(root==NULL) return res;
        con.push(root);
        int now = 1;
        int next = 0;
        while(!con.empty()){
            TreeNode* temp = con.front();
            con.pop();
            now--;
            cp.push_back(temp->val);
            if(temp->left){
                con.push(temp->left);
                next++;
            }
            if(temp->right) {
                con.push(temp->right);
                next++;
            }
            if(now==0){
                now = next ;
                next = 0;
                res.push_back(cp);
                cp.clear();
            }
        }
        return res;
    }
};
