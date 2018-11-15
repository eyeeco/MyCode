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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* head2 = head->next;
        ListNode* p = head;
        while(p&&p->next){
            ListNode* temp = p->next;
            p->next = p->next->next;
            p = temp;
        }
        p = head;
        while(p&&p->next){
            p=p->next;
        }
        p->next = head2;
        return head;
    }
};
