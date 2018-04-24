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
    bool IsSame(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1==NULL&&pRoot2 == NULL) return 1;
        if(pRoot1==NULL) return 0;
        if(pRoot2==NULL) return 1;
        return pRoot1->val==pRoot2->val&&IsSame(pRoot1->left,pRoot2->left)&&IsSame(pRoot1->right,pRoot2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL||pRoot2 == NULL) return 0;
        return IsSame(pRoot1,pRoot2)||IsSame(pRoot1->left,pRoot2)||IsSame(pRoot1->right,pRoot2);
    }
};
