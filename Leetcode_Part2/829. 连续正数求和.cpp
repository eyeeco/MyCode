class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int n = (1 + sqrt(1+8*(long long)N))/2;
        int count = 0;
        for(int i=1; i<=n; i++) {
            int t = 2*N-i*i+i;
            if (t>0&&t%(2*i)==0) count++;
        }
        return count;
    }
};
