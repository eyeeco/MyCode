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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        TreeNode* temp;
        if(root) que.push(root);
        while(!que.empty()){
            temp = que.front();
            res.push_back(temp->val);
            que.pop();
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
        }
        return res;
    }
};
