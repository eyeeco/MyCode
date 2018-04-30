/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Convert_sub(TreeNode* pRootOfTree,TreeNode* &pList){
        if(pRootOfTree == NULL) return ;
        if(pRootOfTree->left) Convert_sub(pRootOfTree->left,pList);
        pRootOfTree->left = pList;
        if(pList!=NULL) pList->right = pRootOfTree;
        pList = pRootOfTree;
        if(pRootOfTree->right) Convert_sub(pRootOfTree->right,pList);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pList =NULL;
        Convert_sub(pRootOfTree, pList);
        while(pRootOfTree&&pRootOfTree->left) pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }
};
