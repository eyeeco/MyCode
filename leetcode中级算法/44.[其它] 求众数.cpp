class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int num, count = 0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                num = nums[i];
                count++;
            }else if(num==nums[i]) count++;
            else count--;
        }
        return num;
    }
};
