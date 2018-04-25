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
    void path(TreeNode* root,vector<vector<int>>& res,vector<int> temp, int expectNumber){
        if(root==NULL) return ;
        if(root->val==expectNumber&&root->left==NULL&&root->right==NULL) {
            temp.push_back(root->val);
            res.push_back(temp);
        }
        else if(root->val<expectNumber){
            temp.push_back(root->val);
            path(root->left,res,temp,expectNumber - root->val);
            path(root->right,res,temp,expectNumber - root->val);
        }
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        vector<int> temp;
        path(root,res,temp,expectNumber);
        return res;
    }
};
