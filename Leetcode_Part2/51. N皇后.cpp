class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> con;
        vector<vector<string>> res;
        place(con, res, n);
        return res;
    }
    void place(vector<int>& con, vector<vector<string>>& res, int n){
        if (con.size() == n) {
            vector<string> temp;
            for (int i=0;i<con.size(); i++) {
                string str;
                int a = con[i], b = n - con[i] - 1;
                while(a--) str += '.';
                str += 'Q';
                while(b--) str += '.';
                temp.push_back(str);
            }
            res.push_back(temp);
            return ;
        }
        for (int i=0; i<n; i++) {
            con.push_back(i);
            if (valid(con)) place(con, res, n);
            con.pop_back();
        }
    }
    bool valid(vector<int> con) {
        int len = con.size();
        for(int i=0; i<len-1; i++) {
            if(con[i] == con[len-1] || len-1-i == con[len-1]-con[i]
               || len-1-i == con[i] - con[len-1]) return false;
        }
        return true;
    }
};
