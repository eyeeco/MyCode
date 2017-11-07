class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> temp(30,0);
        int sum=0;
        for(auto num : nums){
            int i=0;
            while(num!=0){
                if((num&1)==1) temp[i]++;
                num=num>>1;
                i++;
            }
        }
        for(int j=0;j<temp.size();j++){
            sum+= temp[j]*(nums.size()-temp[j]);
        }
        return sum;
    }
};