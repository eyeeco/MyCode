class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        res.push_back(temp);
        iter(res,nums,0);
        return res;
    }
    void iter(vector<vector<int>>& res,vector<int>& nums, int n){
        if(n<nums.size()){
            vector<vector<int>> ex;
            for(int i=0;i<res.size();i++){
                vector<int> temp = res[i];
                temp.push_back(nums[n]);
                ex.push_back(res[i]);
                ex.push_back(temp);
            }
            res = ex;
            iter(res,nums,n+1);
        }
    }
};
