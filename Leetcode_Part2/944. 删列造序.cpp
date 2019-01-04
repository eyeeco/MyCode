class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int count = 0;
        for (int j=0; j<A[0].size(); j++) {
            int k = 0;
            for (int i=0; i<A.size()-1; i++) {
                if (A[i][j] > A[i+1][j]) {
                    k = 1; break;
                }
            }
            count += k;
        }
        return count;
    }
};
