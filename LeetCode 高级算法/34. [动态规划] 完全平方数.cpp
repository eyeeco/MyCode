class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n);
        int t = 1;
        for (int i = 1; i <= n; i++) {
            if(i == t*t) {
                t++;
                dp[i] = 1;
            } else {
                for (int j = 1; j < t; j++) {
                    dp[i] = min(dp[i], dp[i-j*j]+1);
                }
            }
        }
        return dp[n];
    }
};
