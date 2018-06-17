/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    bool removeNode(ListNode* pNode) {
        if(pNode==NULL||pNode->next==NULL) return false;
        while(pNode->next!=NULL){
            pNode->val = pNode->next->val;
            pNode = pNode->next;
        }
        pNode = NULL;
        return true;
    }
};
