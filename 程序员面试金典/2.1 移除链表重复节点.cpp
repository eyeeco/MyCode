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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL || k==0) return NULL;
        ListNode* p = pListHead;
        ListNode* q = pListHead;
        while(k--){
            if(q) q = q->next;
            else return NULL;
        }
        while(q!=NULL){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
