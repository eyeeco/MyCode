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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> con;
        unordered_map<TreeNode*, int> func;
        vector<int> res;
        while (root||!con.empty()) {
            while (root) {con.push(root); root = root->left;}
            if (!con.empty()) {
                root = con.top();
                con.pop();
                if (!func.count(root)) {
                    func[root]++;
                    con.push(root);
                    root = root->right;
                } else {
                    res.push_back(root->val);
                    root = NULL;
                }
            }
        }
        return res;
    }
};
