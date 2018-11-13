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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* q = head;
        while(n--){
            q = q->next;
        };
        while(p&&q&&q->next){
            p = p->next;
            q = q->next;
        }
        if(q==NULL)
            head = head->next;
        else
            p->next = p->next->next;
        return head;
    }
};
