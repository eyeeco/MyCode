class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int sum = 0;
        sort(A.begin(), A.end());
        for(int i=A.size()-1; i>=2; i--){
            if(A[i-2]+A[i-1] > A[i]){
                sum = max(sum, A[i-2]+A[i-1]+A[i]);
            }
        }
        return sum;
    }
};
