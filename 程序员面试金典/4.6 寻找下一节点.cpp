/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Successor {
public:
    int findSucc(TreeNode* root, int p) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        int isfound = 0;
        while(cur!=NULL||!s.empty()){
            if(cur!=NULL){
                s.push(cur);
                cur = cur->left;
            }else{
                TreeNode* q = s.top();
                s.pop();
                if(isfound) return q->val;
                if(q->val==p) isfound = 1;
                cur = q->right;
            }
        }
        return -1;
    }
};
