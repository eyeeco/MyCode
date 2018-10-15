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
class Converter {
private:
    ListNode* head = new ListNode(-1);
    ListNode* p = head;
public:
    ListNode* treeToList(TreeNode* root) {
        // write code here
        if(root){
            if(root->left) treeToList(root->left);
            p->next = new ListNode(root->val);
            p = p->next;
            if(root->right) treeToList(root->right);
        }
        return head->next;
    }
};
