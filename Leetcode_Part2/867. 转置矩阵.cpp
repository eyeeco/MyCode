class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<int> temp(A.size());
        vector<vector<int>> con(A[0].size(), temp);
        for (int i=0; i<A.size(); i++) {
            for(int j=0; j<A[0].size(); j++){
                con[j][i] = A[i][j];
            }
        }
        return con;
    }
};
