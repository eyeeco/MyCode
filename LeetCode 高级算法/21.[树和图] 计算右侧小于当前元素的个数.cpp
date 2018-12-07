class SearchTree{
public:
    int val;
    int less;
    SearchTree *left, *right;
    SearchTree(int v):val(v),less(0),left(NULL),right(NULL){};

    void insert(SearchTree* node){
        if(node==NULL) return ;
        if(node->val<val){
            less++;
            if(left) left->insert(node);
            else left = node;
        }else{
            if(right) right->insert(node);
            else right = node;
        }
    }
    int search(SearchTree* node){
        if(val==node->val){
            return less;
        }else if(node->val<val){
            //if(left==NULL) return -1;
            return left->search(node);
        }else{
            //if(right==NULL) return -1;
            return less+1+ right->search(node);
        }
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        if(len==0) return res;
        SearchTree* root = new SearchTree(nums[len-1]);
        res.push_back(0);
        for(int i=len-2;i>=0;i--){
            SearchTree* temp = new SearchTree(nums[i]);
            root->insert(temp);
            res.push_back(root->search(temp));
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
