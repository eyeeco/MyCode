/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> con;
        if(root==NULL) return;
        con.push(root);
        TreeLinkNode* last = NULL;
        int cur = 1, next =0;
        while(!con.empty()){
            TreeLinkNode* temp = con.front();
            cur--;
            con.pop();
            temp->next = last;
            last = temp;
            if(temp->right) {
                con.push(temp->right);
                next++;
            }
            if(temp->left) {
                con.push(temp->left);
                next++;
            }
            if(cur==0){
                last = NULL;
                cur = next;
                next = 0;
            }
        }
        return ;
    }
};
