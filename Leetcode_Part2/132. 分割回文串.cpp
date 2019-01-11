class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.size()+1);
        vector<vector<int>> con(s.size()+1, dp);
        dp[s.size()] = -1;
        for(int j=s.size()-1; j>=0; j--) {
            dp[j] = s.size();
            for(int i=j; i<s.size(); i++) {
                if(s[i]==s[j]&&(i-j<2||con[j+1][i-1])) {
                    con[j][i] = 1;
                    dp[j] = min(dp[j], dp[i+1]+1);
                }
            }
        }
        return dp[0];
    }
};
