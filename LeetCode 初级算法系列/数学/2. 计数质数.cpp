class Solution {
public:
    int countPrimes(int n) {
        vector<int> num(n+1,1);
        int count = 0;
        for(int i=2;i<n;i++){
            if(num[i]){
                for(int j=i+i;j<n;j+=i){
                    num[j]=0;
                }
                count++;
            }
        }
        return count;
    }
};
