/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
public:
    TreeLinkNode* getFirst(TreeLinkNode* pNode){
        if(pNode->left) return getFirst(pNode->left);
        return pNode;
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL) return NULL;
        if(pNode->right) return getFirst(pNode->right);
        while(pNode->next && pNode->next->right==pNode){
            pNode=pNode->next;
        }
        return pNode->next;
    }
};
