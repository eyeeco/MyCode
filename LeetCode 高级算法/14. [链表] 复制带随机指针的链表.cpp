/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* p = head;
        if(p==NULL) return NULL;
        while(p!=NULL){
            RandomListNode* temp = new RandomListNode(p->label);
            temp->next = p->next;
            p->next = temp;
            p = temp->next;
        }
        p = head;
        while(p!=NULL){
            if(p->random!=NULL) p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        RandomListNode* copy = p->next;
        RandomListNode* q = copy;
        while(q&&q->next){
            p->next = p->next->next;
            q->next = q->next->next;
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        return copy;
    }
};
