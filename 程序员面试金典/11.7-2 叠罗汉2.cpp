class Stack {
public:

    int getHeight(vector<vector<int> > actors, int n) {
        // write code here
        sort(actors.begin(),actors.end());
        vector<int> dp(n,1);
        int num =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(actors[j][1]<actors[i][1]&&(dp[j]+1)>dp[i])
                    dp[i] = dp[j]+1;
            }
            num = max(num,dp[i]);
        }
        return num;
    }
};
