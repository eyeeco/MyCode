class Solution {
public:
    int fib(int N) {
        int a=0, b=1;
        while (N--) {
            b = a + b;
            a = b - a;
        }
        return a;
    }
};
