class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(hash.count(nums[i])){
                res.push_back(hash[nums[i]]);
                res.push_back(i);
                return res;
            }else{
                hash[target-nums[i]] = i;
            }
        }
        return res;
    }
};
