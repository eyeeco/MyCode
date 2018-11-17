/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static int xx = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int kth(TreeNode* root, int& k){
        if(root==NULL) return 0;
        int f = kth(root->left,k);
        if(f) return f;
        if(--k==0) return root->val;
        return kth(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return kth(root,k);
    }
};
