class Box {
public:
    int getHeight(vector<int> w, vector<int> l, vector<int> h, int n) {
        // write code here
        for (int i=0;i<w.size();i++){
            for(int j=i;j<w.size();j++){
                if(w[i]<w[j]){
                    swap(w[i],w[j]);
                    swap(l[i],l[j]);
                    swap(h[i],h[j]);
                }
            }
        }
        vector<int> dp(w.size());
        int res = 0;
        for(int i=0;i<h.size();i++){
            dp[i] = h[i];
            for(int j=0;j<i;j++){
                if(w[j]>w[i]&&l[j]>l[i])
                    dp[i] = max(dp[i],dp[j]+h[i]);
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};
