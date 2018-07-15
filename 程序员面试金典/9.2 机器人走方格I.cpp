class Robot {
public:
    int countWays(int x, int y) {
        vector<int> temp(x,0);
        vector<vector<int>> res(y,temp);
        res[0][0] = 1;
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[0].size();j++){
                if(i>0) res[i][j]+=res[i-1][j];
                if(j>0) res[i][j]+=res[i][j-1];
            }
        }
        return res[y-1][x-1];
    }
};
