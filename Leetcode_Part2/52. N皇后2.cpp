class Solution {
public:
    int totalNQueens(int n) {
        vector<int> con;
        int count = 0;
        place(con, count, n);
        return count;
    }
    void place(vector<int>& con, int& count, int n){
        if (con.size() == n) {
            count++;
            return ;
        }
        for (int i=0; i<n; i++) {
            con.push_back(i);
            if (valid(con)) place(con, count, n);
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
