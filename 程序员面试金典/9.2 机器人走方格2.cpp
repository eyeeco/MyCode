class Robot {
public:
    int countWays(vector<vector<int> > map, int x, int y) {
        vector<int> temp(map[0].size(),0);
        vector<vector<int>> road(map.size(),temp);
        road[0][0] = 1;
        for(int i =0;i<map.size();i++){
            for(int j=0;j<map[0].size();j++){
                if(map[i][j]==1){
                    if(i>0) road[i][j]+= road[i-1][j];
                    if(j>0) road[i][j]+= road[i][j-1];
                }else{
                    road[i][j] = 0;
                }
            }
        }
        return road[map.size()-1][map[0].size()-1];
    }
};
