class Solution {
public:
    int Height(TreeNode* pRoot){
        if(pRoot==NULL) return 0;
        int left = Height(pRoot->left);
        if(left==-1) return -1;
        int right = Height(pRoot->right);
        if(right==-1) return -1;
        return abs(left-right)<=1?max(left,right)+1:-1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return Height(pRoot)!=-1;
    }
};
