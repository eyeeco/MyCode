class Different {
public:
    bool checkDifferent(string iniString) {
        vector<int> res(256,0);
        for(char a:iniString){
            if(res[a]) return false;
            else res[a]++;
        }
        return true;
    }
};
