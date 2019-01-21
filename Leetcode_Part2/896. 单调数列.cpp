class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        return decrease(A)||increase(A);
    }
    bool decrease(vector<int>& A) {
        for (int i=1; i<A.size(); i++) {
            if(A[i] > A[i-1]) return false;
        }
        return true;
    }
    bool increase(vector<int>& A) {
        for (int i=1; i<A.size(); i++) {
            if(A[i] < A[i-1]) return false;
        }
        return true;
    }
};
