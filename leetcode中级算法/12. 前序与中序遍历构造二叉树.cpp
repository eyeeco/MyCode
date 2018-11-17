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
    int findPos(vector<int> vec, int order){
        for(int i=0;i<vec.size();i++){
            if(vec[i]==order) return i;
        }
        return -1;
    }
    TreeNode* bulid(vector<int> preorder,vector<int> inorder,int pos, int left, int right){
        if(left>right) return NULL;
        TreeNode* root = new TreeNode(preorder[pos]);
        int inpos = findPos(inorder,preorder[pos]);
        root->left = bulid(preorder,inorder,pos+1,left,inpos-1);
        root->right = bulid(preorder,inorder,pos+inpos-left+1,inpos+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return bulid(preorder,inorder,0,0,preorder.size()-1);
    }

};
