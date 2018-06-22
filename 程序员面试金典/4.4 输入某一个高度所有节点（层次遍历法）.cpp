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
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        if(root==NULL||dep<1) return NULL;
        queue<TreeNode*> q;
        int layer = 1;
        int count1 = 1;
        int count2 = 0;
        ListNode* p = new ListNode(-1);
        ListNode* res = p;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(layer == dep){
                p->next = new ListNode(temp->val);
                p=p->next;
            }
            if(temp->left){
                q.push(temp->left);
                count2++;
            };
            if(temp->right){
                q.push(temp->right);
                count2++;
            }
            if(--count1 == 0){
                count1 = count2;
                count2 = 0;
                layer++;
            }
        }
        return res->next;
    }
};
