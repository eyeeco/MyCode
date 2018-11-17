static int is_sync = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int dfs(vector<vector<char>>& grid,int i,int j){
        if(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]=='1'){
            grid[i][j]='2';
            dfs(grid,i+1,j);
            dfs(grid,i-1,j);
            dfs(grid,i,j+1);
            dfs(grid,i,j-1);
            return 1;
        }
        return 0;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++){
               count+= dfs(grid,i,j);
           }
        }
        return count;
    }
};
