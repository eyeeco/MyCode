class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> temp(n+1);
        vector<vector<int>> con(n+1, temp);
        for(int j=1; j<n+1; j++) {
            con[j][j] = nums[j-1];
            for(int i=j-1; i>=1; i--) {
                if(j==n) con[i][j] = max(con[i][j-1], con[i+1][j-2]+con[j][j]);
                else con[i][j] = max(con[i][j-1], con[i][j-2]+con[j][j]);
            }
        }
        return con[1][n];
    }
};
