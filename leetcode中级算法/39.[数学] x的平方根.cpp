class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int left = 1, right = x;
        while(left<right){
            int mid = (left+right)/2;
            if(mid<= x/mid){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left-1;
    }
};

// 牛顿法
class Solution{
public:
    int mySqrt(int x){
        double x0 = 1.0;
        double eps = 0.01;
        double x1;
        while(1){
            x1 = (x0 + x/x0)/2;
            if(abs(x1*x1-x)<eps) break;
            else x = x1;
        }
    }
}
