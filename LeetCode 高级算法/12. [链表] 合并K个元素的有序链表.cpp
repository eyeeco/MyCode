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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a,ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> con(cmp);
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        for(auto li:lists){
            if(li!=NULL) con.push(li);
        }
        while(!con.empty()){
            ListNode* temp = con.top();
            con.pop();
            if(temp->next) con.push(temp->next);
            p->next = temp;
            p = p->next;
        }
        return head->next;
    }
};
