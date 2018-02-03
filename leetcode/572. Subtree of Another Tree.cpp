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
    bool isSame(TreeNode* s, TreeNode* t){
        if(s&&t&&s->val==t->val) return isSame(s->left,t->left)&&isSame(s->right,t->right);
        if(s==NULL&&t==NULL) return true;
        return false;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSame(s,t)||(s&&isSubtree(s->left,t))||(s&&isSubtree(s->right,t));
    }
};
