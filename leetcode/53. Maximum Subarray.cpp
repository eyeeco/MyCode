class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        for(int i = 1;i<nums.size();i++){
            nums[i] = max(nums[i],nums[i-1]+nums[i]);
        }
        int res = INT_MIN;
        for(auto num:nums){
            res =max(res,num); 
        }
        return res;
    }
};