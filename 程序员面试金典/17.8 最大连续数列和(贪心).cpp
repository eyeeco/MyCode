class MaxSum {
public:
    int getMaxSum(vector<int> A, int n) {
        // write code here
        vector<int> dp(n);
        int num = A[0];
        dp[0] = A[0];
        for(int i=1;i<n;i++){
            dp[i] = max((A[i]+dp[i-1]),A[i]);
            num = max(num,dp[i]);
        }
        return num;
    }
};
