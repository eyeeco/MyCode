class GoUpstairs {
public:
    int countWays(int n) {
        vector<int> temp(max(3,n));
        temp[0] = 1;
        temp[1] = 2;
        temp[2] = 4;
        for(int i=3;i<n;i++){
            temp[i] = ((temp[i-1] + temp[i-2])%1000000007 + temp[i-3])%1000000007;
        }
        return temp[n-1];
    }
};
