/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
private:
    vector<int> res;
public:
    void dfs(TreeNode* p){
        if(p==NULL){
            res.push_back(0x23333);
        }else{
            res.push_back(p->val);
            dfs(p->left);
            dfs(p->right);
        }
    }
    TreeNode* dfs2(int* &num){
        if(*num==0x23333){
            num++;
            return NULL;
        }else{
            TreeNode* node = new TreeNode(*num);
            ++num;
            node->left = dfs2(num);
            node->right = dfs2(num);
            return node;
        }
    }
    char* Serialize(TreeNode *root) {
        res.clear();
        dfs(root);
        int* s=new int[res.size()];
        for(unsigned i=0;i<res.size();i++) s[i] = res[i];
        return (char*)s;
    }
    TreeNode* Deserialize(char *str) {
        int* num = (int*)str;
        return dfs2(num);
    }
};
