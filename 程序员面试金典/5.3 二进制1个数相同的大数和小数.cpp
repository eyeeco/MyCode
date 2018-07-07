class CloseNumber {
public:
    vector<int> getCloseNumber(int x) {
        vector<int> res;
        int cm0=0,cm1=0,cn0=0,cn1=0;
        int c = x,d = x,p,q;
        while((c&1)==0&&c!=0){
            cm0++;
            c >>= 1;
        }
        while((c&1)==1){
            cm1++;
            c >>= 1;
        }
        while((d&1)==1){
            cn1++;
            d >>= 1;
        }
        while((d&1)==0&&d!=0){
            cn0++;
            d >>= 1;
        }
        p = cm1+cm0;
        q = cn1+cn0;
        res.push_back((x - (1<<(cn1))-(1<<(cn0-1)) +1));
        res.push_back((x + (1<<(cm1-1)) + (1<<cm0) -1));
        return res;
    }
};
