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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int flag = 0;
        while(p1!=NULL&&p2!=NULL){
            int sum = p1->val + p2->val + flag;
            flag = sum/10;
            p1->val = sum%10;
            if(p1->next==NULL) break;
            p1=p1->next;
            p2=p2->next;
        }
        if(p2){
            if(p2->next){
                p1->next = p2->next;
                p1 = p2->next;
            }else{
                if(flag==1){
                    ListNode* temp = new ListNode(1);
                    p1->next = temp;
                    return l1;
                }
            }
        }
        while(p1&&flag){
            int sum = p1->val + flag;
            p1->val = sum%10;
            flag = sum/10;
            if(p1->next==NULL) break;
            p1=p1->next;
        }
        if(flag==1){
            ListNode* temp = new ListNode(1);
            p1->next = temp;
        }
        return l1;
    }
};
