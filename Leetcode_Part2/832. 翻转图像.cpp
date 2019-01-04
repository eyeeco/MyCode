class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i=0; i<A.size(); i++) {
            int len = A[0].size();
            for (int j=0; j<len/2; j++) {
                swap(A[i][j], A[i][len-1-j]);
            }
            for (int j=0; j<len; j++) {
                A[i][j] = !A[i][j];
            }
        }
        return A;
    }
};
