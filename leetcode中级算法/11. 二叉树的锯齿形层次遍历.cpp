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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> con;
        vector<vector<int>> res;
        vector<int> child;
        if(root==NULL) return res;
        con.push(root);
        int cur = 1, next = 0;
        int flag = 1;
        while(!con.empty()){
            TreeNode* temp = con.front();
            con.pop();
            cur--;
            child.push_back(temp->val);
            if(temp->left){
                con.push(temp->left);
                next++;
            }
            if(temp->right){
                con.push(temp->right);
                next++;
            }
            if(cur==0){
                if(flag<0) reverse(child.begin(),child.end());
                flag = -flag;
                cur = next;
                next = 0;
                res.push_back(child);
                child.clear();
            }
        }
        return res;
    }
};
