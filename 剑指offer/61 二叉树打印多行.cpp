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
            queue<TreeNode*> line;
            vector<vector<int>> res;
            vector<int> sub_res;
            TreeNode* temp;
            int to_print = 1;
            int next = 0;
            if(pRoot==NULL) return res;
            line.push(pRoot);
            while(!line.empty()){
                temp = line.front();
                line.pop();
                to_print--;
                sub_res.push_back(temp->val);
                if(temp->left) {
                    line.push(temp->left);
                    next++;
                }
                if(temp->right) {
                    line.push(temp->right);
                    next++;
                }
                if(to_print==0){
                    res.push_back(sub_res);
                    sub_res.clear();
                    to_print = next;
                    next=0;
                }
            }
            return res;
        }

};
