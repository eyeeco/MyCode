/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Balance {
public:
    int Height(TreeNode* root){
        if(root==NULL) return 0;
        int left = Height(root->left);
        if(left==-1) return -1;
        int right = Height(root->right);
        if(right==-1) return -1;
        return abs(left-right)<=1?max(left,right)+1:-1;
    }
    bool isBalance(TreeNode* root) {
        return Height(root)!=-1;
    }
};
