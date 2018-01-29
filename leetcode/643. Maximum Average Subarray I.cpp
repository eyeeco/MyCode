class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0,res=INT_MIN;
        for(int j=0;j<nums.size();j++){
            if(j<k) sum+=nums[j];
            else{
                res = max(res,sum);
                sum += nums[j]-nums[j-k];
            }
        }
        return max(res,sum)/k;
    }
};
