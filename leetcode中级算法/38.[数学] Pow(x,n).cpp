class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            if(n==INT_MIN) return x*myPow(1/x,INT_MAX);
            return myPow(1/x,-n);
        }
        else if(n==0) return 1;
        else{
            double res = 1;
            if(n%2==1) res*=x;
            double temp = myPow(x,n/2);
            return res*temp*temp;
        }
    }
};
