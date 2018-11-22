class Solution {
public:
    int getSum(int a, int b) {
        while(a&&b){
            int temp = (a&b)<<1;
            b = a^b;
            a = temp;
        }
        return a?a:b;
    }
};
