class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,sub=0;
        for(int num:nums){
            sum+=num;
        }
        for(int i=0;i<nums.size();i++){
            sum-=nums[i];
            if(i>0) sub+=nums[i-1];
            if(sub==sum) return i;
        }
        return -1;
    }
};
