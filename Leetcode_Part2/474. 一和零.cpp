class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> con(m+1, vector<int>(n+1));
        for(string s:strs) {
            int zeros = 0, ones = 0;
            for(char item:s) {
                if(item=='0') zeros++;
                else ones++;
            }
            for(int i=m; i>=zeros; i--) {
                for(int j=n; j>=ones; j--) {
                    con[i][j] = max(con[i][j], con[i-zeros][j-ones]+1);
                }
            }
        }
        return con[m][n];
    }
};
