/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        vector<int> temp;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        TreeNode* node;
        if(pRoot!= NULL) s1.push(pRoot);
        while(!s1.empty()||!s2.empty()){
            temp.clear();
            if(!s1.empty()){
                while(!s1.empty()){
                    node = s1.top();
                    s1.pop();
                    temp.push_back(node->val);
                    if(node->left) s2.push(node->left);
                    if(node->right) s2.push(node->right);
                }
                res.push_back(temp);
            }else{
                while(!s2.empty()){
                    node = s2.top();
                    s2.pop();
                    temp.push_back(node->val);
                    if(node->right) s1.push(node->right);
                    if(node->left) s1.push(node->left);
                }
                res.push_back(temp);
            }
        }
        return res;
    }

};
