class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        auto t = lower_bound(A.begin(), A.end(), 0);
        vector<int> res;
        int right = t-A.begin();
        int left = right-1;
        while(left>=0&&right<A.size()) {
            if (abs(A[left])<abs(A[right])) {
                res.push_back(A[left]*A[left]); left--;
            } else {
                res.push_back(A[right]*A[right]); right++;
            }
        }
        while(left>=0) {
            res.push_back(A[left]*A[left]); left--;
        }
        while(right<A.size()) {
            res.push_back(A[right]*A[right]); right++;
        }
        return res;
    }
};
