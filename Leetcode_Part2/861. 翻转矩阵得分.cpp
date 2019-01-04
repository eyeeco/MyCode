class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int len = A.size();
        for (int i=0; i<len; i++) {
            if (A[i][0] == 0) {
                for (int j=0; j<A[i].size(); j++) {
                    A[i][j] = !A[i][j];
                }
            }
        }
        int sum = 0;
        for (int j=0; j<A[0].size(); j++) {
            int count = 0;
            for (int i=0; i<len; i++) count += A[i][j];
            sum = sum * 2 + max(count, len-count);
        }
        return sum;
    }
};
