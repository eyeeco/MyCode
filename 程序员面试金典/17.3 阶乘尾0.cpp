class Factor {
public:
    int getFactorSuffixZero(int n) {
        // write code here
        int i=5;
        int sum = 0;
        while(n>=i){
            sum+=n/i;
            i*=5;
        }
        return sum;
    }
};
