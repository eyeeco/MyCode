class Solution {
public:
    int divide(int dividend, int divisor) {
        long long flag= 1;
        long long a = (long long)dividend;
        long long b = (long long)divisor;
        long long count, mid,res = 0;
        if(a<0){
            a = - a;
            flag = -flag;
        }
        if(b<0){
            b = - b;
            flag = -flag;
        }
        while(b<=a){
            count = 1;
            mid = b;
            while(mid<=a){
                a-=mid;
                res+= count;
                count = count<<1;
                mid = mid<<1;
            }
        }
        res = flag*res;
        if(res<INT_MIN||res>INT_MAX) return INT_MAX;
        else return res;
    }
};
