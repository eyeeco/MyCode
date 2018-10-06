class Stack {
public:
    int getHeight(vector<int> men, int n) {
        // write code here
        vector<int> dp(n,1);
        int num = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(men[j]<men[i]&&(dp[j]+1)>dp[i])
                    dp[i] = dp[j]+1;
            }
            num = max(dp[i],num);
        }
        return num;
    }
};
