class AlphaMatrix {
public:
    int findAlphaMatrix(vector<string> dic, int n) {
        // write code here
        map<string,int> hash;
        int num = 0;
        for(int i=0;i<n;i++){
            hash[dic[i]]++;
            int res = hash[dic[i]]*dic[i].size();
            num = max(num,res);
        }
        return num;
    }
};
