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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        int count = 0;
        int flag;
        while(p!=NULL&&q!=NULL){
            p=p->next;
            q=q->next;
        }
        while(p!=NULL){
            p=p->next;
            count++;
            flag = 0;
        }
        while(q!=NULL){
            q=q->next;
            count++;
            flag =1;
        }
        p = headA;
        q = headB;
        while(count--){
            if(!flag) p = p->next;
            else q=q->next;
        }
        while(p&&q){
            if(p->val==q->val) return p;
            p=p->next;
            q=q->next;
        }
        return NULL;
    }
};
