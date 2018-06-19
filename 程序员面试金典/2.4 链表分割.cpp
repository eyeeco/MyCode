/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* ahead = NULL;
        ListNode* atail = NULL;
        ListNode* bhead = NULL;
        ListNode* btail = NULL;
        while(pHead){
            ListNode* next = pHead->next;
            pHead->next = NULL;
            if(pHead->val<x){
                if(ahead==NULL){
                    ahead = pHead;
                    atail = pHead;
                }else{
                    atail->next = pHead;
                    atail = atail->next;
                }
            }else{
                if(bhead==NULL){
                    bhead = pHead;
                    btail = pHead;
                }else{
                    btail->next = pHead;
                    btail = btail->next;
                }
            }
            pHead = next;
        }
        if(ahead==NULL) return bhead;
        atail->next = bhead;
        return ahead;
    }
};
