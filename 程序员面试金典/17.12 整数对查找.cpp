class FindPair {
public:
    int countPairs(vector<int> A, int n, int sum) {
        // write code here
        map<int,int> hash;
        int res = 0;
        for(int num:A){
            if(hash[num]) res += hash[num];
            hash[sum-num]++;
        }
        return res;
    }
};
