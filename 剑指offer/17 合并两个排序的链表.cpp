/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *root = new ListNode(0);
        ListNode *t = root;
        ListNode *p = pHead1;
        ListNode *q = pHead2;
        while(p&&q){
            if(p->val < q ->val){
                t->next = p;
                t=t->next;
                p=p->next;
            }else{
                t->next = q;
                t=t->next;
                q=q->next;
            }
        }
        while(p){
            t->next = p;
            t=t->next;
            p=p->next;
        }
        while(q){
            t->next = q;
            t=t->next;
            q=q->next;
        }
        return root->next;
    }
};
