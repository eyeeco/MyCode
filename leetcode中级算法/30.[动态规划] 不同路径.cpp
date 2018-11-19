class Solution {
public:
    int uniquePaths(int m, int n) {
        long long sum = 1;
        for(int i=1;i<=m-1;i++){
            sum*= i+n-1;
            sum/= i;
        }
        return sum;
    }
};
