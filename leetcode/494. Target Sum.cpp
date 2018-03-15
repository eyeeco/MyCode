class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0,k;
        for(int num:nums) sum+=num;
        if(S<-sum||S>sum||(S+sum)%2==1) return 0;
        k = (S+sum)>>1;
        vector<int> res(k+1,0);
        res[0]=1;
        for(int num:nums){
            for(int i=k;i>=num;i--){
                res[i] += res[i-num];
            }
        }
        return res[k];
    }
};
