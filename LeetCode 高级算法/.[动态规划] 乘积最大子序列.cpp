class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int num1=1,num2=1,num3=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int temp;
            temp = max(num1*nums[i],max(num2*nums[i],nums[i]));
            num2 = min(num1*nums[i],min(num2*nums[i],nums[i]));
            num1 = temp;
            num3 = max(num3,num1);
        }
        return num3;
    }
};
