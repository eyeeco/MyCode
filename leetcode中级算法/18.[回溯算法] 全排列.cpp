class Solution {
public:
    void order(vector<vector<int>>& res, vector<int> nums, vector<int>& flag, vector<int>& gen){
        if(gen.size()==nums.size()){
            res.push_back(gen);
            return ;
        }else{
            for(int i=0;i<nums.size();i++){
                if(flag[i]){
                    gen.push_back(nums[i]);
                    flag[i] = 0;
                    order(res,nums,flag,gen);
                    flag[i] = 1;
                    gen.pop_back();
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> flag(nums.size(),1);
        vector<int> gen;
        order(res,nums,flag,gen);
        return res;
    }
};
