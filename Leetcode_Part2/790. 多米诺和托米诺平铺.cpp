class Solution {
public:
    int numTilings(int N) {
        vector<int> dp(N+1);
        if(N==1) return 1;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=N;i++) {
            dp[i] = (2*dp[i-1]%1000000007 + dp[i-3])%1000000007;
        }
        return dp[N];
    }
};
