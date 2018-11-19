
// 动态规划算法 O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int res = 1;
        if(nums.size()==0) return 0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i] = max(dp[i],dp[j]+1);
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};

// 动态规划算法 + 贪心 O(nlog(n))
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        if(nums.size()==0) return 0;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>*(dp.end()-1)) dp.push_back(nums[i]);
            else{
                auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
                *it = nums[i];
            }
        }
        return dp.size();
    }
};
