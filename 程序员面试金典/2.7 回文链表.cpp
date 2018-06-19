/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        if(pHead==NULL||pHead->next==NULL) return true;
        ListNode* slow = pHead;
        ListNode* fast = pHead->next;
        stack<int> con;
        int temp;
        while(fast!=NULL&&fast->next!=NULL){
            con.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL) con.push(slow->val);
        slow = slow->next;
        while(slow!=NULL&&!con.empty()){
            temp = con.top();
            if(temp != slow->val) return false;
            con.pop();
            slow = slow->next;
        }
        return true;
    }
};
