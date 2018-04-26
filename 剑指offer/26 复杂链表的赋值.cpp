/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode* temp = pHead;
        while(temp){
            RandomListNode* p = new RandomListNode(temp->label);
            p->next = temp->next;
            temp->next = p;
            temp = p->next;
        }
        temp = pHead;
        while(temp){
            if(temp->random) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        RandomListNode* pClone = pHead->next;
        RandomListNode* p;
        temp = pHead;
        while(temp->next){
            p = temp->next;
            temp->next = p->next;
            temp = p;
        }
        return pClone;
    }
};
