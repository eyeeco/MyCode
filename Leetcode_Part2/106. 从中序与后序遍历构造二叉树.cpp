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
    TreeNode* bulid(vector<int>& inorder, vector<int>& postorder, int postpos, int left, int right) {
        if (left > right) return NULL;
        int pivot = postorder[postpos];
        int pos = find(inorder.begin(), inorder.end(), pivot) - inorder.begin();
        TreeNode* root = new TreeNode(pivot);
        root->left = bulid(inorder, postorder, postpos-right+pos-1,left, pos-1);
        root->right = bulid(inorder, postorder, postpos-1, pos+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return bulid(inorder, postorder, postorder.size()-1, 0, inorder.size()-1);
    }
};
