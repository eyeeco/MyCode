class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> con(nums);
        con.insert(con.begin(),1);
        con.insert(con.end(),1);
        int n = con.size();
        int dp[n][n] = {};
        for (int k=2; k<n; k++) {
            for (int left = 0; left<n-k; left++) {
                int right = left + k;
                for (int i = left+1; i< right; i++) {
                    dp[left][right] = max(dp[left][right],
                        dp[left][i] + dp[i][right] + con[left]*con[i]*con[right]);
                }
            }
        }
        return dp[0][n-1];
    }
};
