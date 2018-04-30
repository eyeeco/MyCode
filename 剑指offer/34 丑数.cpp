class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		vector<int> dp(index , 1);
        if(index<=0) return 0;
		int m = 0, n = 0, k = 0;
		int tar = 0;
		for (int i = 1; i < index; i++){
			dp[i] = min(dp[m] * 2, min(dp[n] * 3, dp[k] * 5));
			if (dp[i] == dp[m] * 2) m++;
			if (dp[i] == dp[n] * 3) n++;
			if (dp[i] == dp[k] * 5) k++;
		}
		return dp[index-1];
	}
};
