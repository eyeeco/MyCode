class Solution {
public:
    int arrangeCoins(int n) {
        long long t = n;
        return (sqrt(1+8*t)-1)/2;
    }
};
