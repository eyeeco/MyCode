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
    ListNode* reverseList(ListNode* head) {
        ListNode* supp = new ListNode(0);
        ListNode* p = head;
        while(p){
            ListNode* temp = p;
            p = p->next;
            temp ->next = supp->next;
            supp ->next = temp;
        }
        return supp->next;
    }
};
