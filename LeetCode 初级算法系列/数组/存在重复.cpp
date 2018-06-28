class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> desk;
        for(int i=0;i<nums.size();i++){
            if(desk.count(nums[i])) return true;
            desk.insert(nums[i]);
        }
        return false;
    }
};
