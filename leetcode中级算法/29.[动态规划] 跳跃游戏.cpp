class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0, end = 0;
        if(nums.size()==0) return false;
        while(start<=end){
            end = max(end,start + nums[start]);
            start++;
            if(end>=nums.size()-1) return true;
        }
        return false;
    }
};
