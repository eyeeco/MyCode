class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_num = -1;
        vector<int> m_vec,n_vec;
        int sum = 0;
        for(int i =0;i<m;i++){
            max_num = -1;
            for(int j=0;j<n;j++) max_num = max(max_num,grid[i][j]);
            m_vec.push_back(max_num);
        }
        for(int j=0;j<n;j++){
            max_num = -1;
            for(int i =0;i<m;i++) max_num = max(max_num,grid[i][j]);
            n_vec.push_back(max_num);
        }
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                sum+=min(m_vec[i],n_vec[j])-grid[i][j];
            }
        }
        return sum;
    }
};
