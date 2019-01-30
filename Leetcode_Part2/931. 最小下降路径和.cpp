class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int t = A.size(), rs = INT_MAX;
        for(int i=1; i<A.size();i++){
            for(int j=0; j<A[0].size();j++){
                int temp = A[i-1][j];
                if(j>0) temp = min(temp, A[i-1][j-1]);
                if(j<A[i].size()-1) temp = min(temp, A[i-1][j+1]);
                A[i][j] += temp;
            }
        }
        for(int j=0; j<A[0].size(); j++){
            rs = min(rs, A[t-1][j]);
        }
        return rs;
    }
};
