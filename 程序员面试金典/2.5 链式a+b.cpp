/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        int add = 0;
        while(a!=NULL&&b!=NULL){
            ListNode* temp = new ListNode((a->val+b->val+add)%10);
            add = (a->val+b->val+add)/10;
            p->next = temp;
            p = p->next;
            a = a->next;
            b = b->next;
        }
        while(a!=NULL){
            ListNode* temp = new ListNode((a->val+add)%10);
            add = (a->val+add)/10;
            p->next = temp;
            p = p->next;
            a = a->next;
        }
        while(b!=NULL){
            ListNode* temp = new ListNode((b->val+add)%10);
            add = (b->val+add)/10;
            p->next = temp;
            p = p->next;
            b = b->next;
        }
        if(add==1){
            ListNode* temp = new ListNode(1);
            p->next = temp;
        }
        return head->next;
    }
};
