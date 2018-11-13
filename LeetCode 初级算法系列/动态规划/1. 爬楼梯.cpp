class Solution {
public:
    int climbStairs(int n) {
        int a = 1 ,b = 1;
        while(--n){
            a = a + b;
            b = a - b;
        }
        return a;
    }
};
