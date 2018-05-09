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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL||pHead->next->next==NULL) return NULL;
        ListNode* p = pHead->next;
        ListNode* q = pHead->next->next;
        while(p!=q){
            if(p->next==NULL||q->next->next==NULL) return NULL;
            p = p->next;
            q = q->next->next;
        }
        p = pHead;
        while(p!=q){
            p=p->next;
            q=q->next;
        }
        return q;
    }
};
