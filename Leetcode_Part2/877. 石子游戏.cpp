class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> temp(n);
        vector<vector<int>> f(n, temp);
        vector<vector<int>> g(n, temp);
        for(int i=0;i<n;i++){
            f[i][i] = piles[i];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                f[i][j] = max(piles[i]+g[i+1][j],piles[j]+g[i][j-1]);
                g[i][j] = min(f[i+1][j], f[i][j-1]);
            }
        }
        return f[0][n-1]>g[0][n-1];
    }
};
