class Solution {
public:
    void back_trace(vector<vector<int>>& con, vector<int>& temp, int level, int n, int k) {
        if (temp.size() == k) {
            con.push_back(temp);
            return ;
        }
        for (int i = level; i <= n; i++ ) {
            temp.push_back(i);
            back_trace(con, temp, i+1, n, k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> con;
        vector<int> temp;
        back_trace(con, temp, 1, n, k);
        return con;
    }
};
