/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* head = new ListNode(0);
        ListNode* pt = head;
        while(p!=NULL&&q!=NULL){
            ListNode* temp;
            if(p->val<q->val){
                temp= p;
                p = p->next;
            }else{
                temp = q;
                q = q->next;
            }
            pt->next = temp;
            pt = pt->next;
        }
        if(p!=NULL) pt->next = p;
        if(q!=NULL) pt->next = q;
        return head->next;
    }
};
