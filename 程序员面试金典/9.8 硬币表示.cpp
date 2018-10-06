class Coins {
public:
    int count(int n,int current){
        int next = 0;
        int sum = 0;
        switch(current){
            case 25:
                next = 10;
                break;
            case 10:
                next = 5;
                break;
            case 5:
                next = 1;
                break;
            case 1:
                return 1;
        }
        for(int i=0;i*current<=n;i++){
            sum+= count(n-i*current,next);
        }
        return sum%1000000007;
    }
    int count2(int n){
        vector<int> dp(n+1);
        vector<int> coin = {1,5,10,25};
        dp[0]=1;
        for(int i=0;i<coin.size();i++){
            for(int j=coin[i];j<=n;j++){
                dp[j] = (dp[j]+ dp[j-coin[i]])%1000000007;
            }
        }
        return dp[n];
    }
    int countWays(int n) {
        return count2(n);
    }
};
