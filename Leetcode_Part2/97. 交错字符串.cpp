class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(), n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        if(s3.size()!=m+n) return false;
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i==0&&j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = dp[i][j-1]&&s2[j-1]==s3[i+j-1];
                else if(j==0) dp[i][j] = dp[i-1][j]&&s1[i-1]==s3[i+j-1];
                else dp[i][j] = (dp[i][j-1]&&s2[j-1]==s3[i+j-1])||(dp[i-1][j]&&s1[i-1]==s3[i+j-1]);
            }
        }
        return dp[m][n];
    }
};
