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
    void reorderList(ListNode* head) {
        ListNode* p = head, *q = head;
        if(!head) return ;
        while (q&&q->next&&q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        q = p->next;
        p->next = NULL;
        ListNode* helper = new ListNode(0);
        while(q) {
            ListNode* temp = q->next;
            q->next = helper->next;
            helper->next = q;
            q = temp;
        }
        p = head;
        q = helper->next;
        free(helper);
        while(q) {
            ListNode* temp = q->next;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
            q = temp;
        }
    }
};
