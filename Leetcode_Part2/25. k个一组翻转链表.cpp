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
    ListNode* helper = new ListNode(0);
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            temp = temp->next;
            count++;
            if (count == k) break;
        }
        if (count < k) return head;
        temp = reverseKGroup(temp, k);
        helper->next = temp;
        ListNode* p = head, *cop;
        while (count--) {
            cop = p->next;
            p->next = helper->next;
            helper->next = p;
            p = cop;
        }
        return helper->next;
    }
};
