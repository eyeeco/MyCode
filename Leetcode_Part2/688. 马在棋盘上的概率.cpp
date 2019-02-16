class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        int moves[8][2] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1}};
        vector<vector<double>> dp0(N, vector<double>(N, 1));
        for(int l=0; l<K; l++){
            vector<vector<double>> dp1(N, vector<double>(N, 0));
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    for(auto move:moves){
                        int x = i + move[0];
                        int y = j + move[1];
                        if(valid(x, y, N)) dp1[i][j] += dp0[x][y];
                    }
                }
            }
            dp0 = dp1;
        }
        return dp0[r][c]/pow(8, K);
    }
    bool valid(int x, int y, int N){
        return x>=0&&x<N&&y>=0&&y<N;
    }
};
