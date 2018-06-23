/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class TreeLevel {
private:
    ListNode* head = new ListNode(-1);
    ListNode* p = head;
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        if(root==NULL||dep<1) return NULL;
        if(dep==1){
            p->next = new ListNode(root->val);
            p = p->next;
        }else{
            getTreeLevel(root->left,dep-1);
            getTreeLevel(root->right,dep-1);
        }
        return head->next;
    }
};
