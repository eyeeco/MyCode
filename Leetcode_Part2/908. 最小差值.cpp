class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minA = A[0], maxA = A[0];
        for (int num : A) {
            minA = min(minA, num);
            maxA = max(maxA, num);
        }
        int rs = maxA - minA - 2 * K;
        return rs>0?rs:0;
    }
};
