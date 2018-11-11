class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        if(prices.size()<=1) return sum;
        int num = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>num){
                sum += prices[i]-num;
                num = prices[i];
            }else{
                num = prices[i];
            }
        }
        return sum;
    }
};
