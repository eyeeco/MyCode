class LCA {
public:
    int getLCA(int a, int b) {
        while(a&&b){
            if(a==b) return a;
            else if(a>b) a/=2;
            else b/=2;
        }
        return 0;
    }
};
