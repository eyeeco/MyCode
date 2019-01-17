class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int sum = 0;
        for(int i=0; i<grid.size(); i++) {
            int t1 = 0, t2 = 0;
            for(int j=0; j<grid.size(); j++) {
                t1 = max(t1, grid[i][j]);
                t2 = max(t2, grid[j][i]);
                if(grid[i][j]) sum++;
            }
            sum += t1;
            sum += t2;
        }
        return sum;
    }
};
