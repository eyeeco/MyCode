class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0&&nums[i]<=nums.size()&&nums[nums[i]-1]!=nums[i]){
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[nums[i]-1]!=i+1){
                return nums[i];
            }
        }
        return -1;
    }
};
