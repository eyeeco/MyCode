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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* k = new ListNode(0);
        ListNode* p = pHead;
        ListNode* q = pHead;
        while(p){
            q = q->next;
            p->next = k-> next;
            k->next = p;
            p = q;
        }
        return k->next;
    }
};
