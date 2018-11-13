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
    bool isPalindrome(ListNode* head) {
        int m = 0 , n;
        ListNode* q = head;
        stack<int> con;
        while(q){
            q = q->next;
            m++;
        }
        n = m/2;
        q = head;
        while(n--){
            con.push(q->val);
            q = q->next;
        }
        if(m%2==1) q = q->next;
        while(!con.empty()){
            if(q->val!=con.top())
                return false;
            else{
                con.pop();
                q = q->next;
            }
        }
        return con.empty();
    }
};
