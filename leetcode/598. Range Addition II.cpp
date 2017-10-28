class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(auto op:ops){
            if(op[0]<m) m = op[0];
            if(op[1]<n) n = op[1];
        }
        return m*n;
    }
};