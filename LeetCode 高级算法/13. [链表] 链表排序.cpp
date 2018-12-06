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
    ListNode* sortList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pre=head;
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        while(fast&&fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return merge(left,right);
    }
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while(left!=NULL&&right!=NULL){
            if(left->val<right->val){
                p->next = left;
                p=p->next;
                left = left->next;
            }else{
                p->next = right;
                p=p->next;
                right = right->next;
            }
        }
        while(left!=NULL){
            p->next = left;
            p=p->next;
            left = left->next;
        }
        while(right!=NULL){
            p->next = right;
            p=p->next;
            right = right->next;
        }
        return head->next;
    }
};
