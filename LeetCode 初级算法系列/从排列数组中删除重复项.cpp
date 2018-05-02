class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=0,i=0;
        while(i<nums.size()){
            while(nums[i]==nums[i+1]) i++;
            nums[res] = nums[i];
            res++;
            i++;
        }
        return res;
    }
};
