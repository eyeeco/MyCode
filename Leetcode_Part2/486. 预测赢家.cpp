class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        vector<int> temp(len);
        vector<vector<int>> f(len, temp);
        vector<vector<int>> s(f);
        for ( int j = 0; j < len; j++) {
            f[j][j] = nums[j];
            for (int i = j-1; i >=0; i--) {
                f[i][j] = max(nums[i] + s[i+1][j], nums[j] + s[i][j-1]);
                s[i][j] = min(f[i+1][j], f[i][j-1]);
            }
        }
        return f[0][len-1] >= s[0][len-1];
    }
};
