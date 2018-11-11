class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0 ;
        while(i<nums.size()&&j<nums.size()){
            while(nums[j]==0) j++;
            if(j<nums.size()) nums[i] = nums[j];
            else break;
            i++;
            j++;
        }
        while(i<nums.size()){
            nums[i]=0;
            i++;
        }
    }
};
