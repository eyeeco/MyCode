class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        for(int i=1;i<=amount;i++){
            dp[i] = amount+1;
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};
