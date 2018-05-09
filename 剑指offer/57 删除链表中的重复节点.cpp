/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* p = pHead;
        ListNode* q = new ListNode(0);
        ListNode* res = q;
        q->next = p;
        while(p){
            if(p->next&&p->val==p->next->val){
                while(p->next&&p->val==p->next->val){
                    p = p->next;
                }
                p=p->next;
                q->next=p;
            }else{
                p=p->next;
                q=q->next;
            }
        }
        return res->next;
    }
};
