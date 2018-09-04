class Subset {
public:
    vector<vector<int> > getSubsets(vector<int> A, int n) {
        vector<vector<int>> res;
        int size = 1<<n;
        for(int i=size-1;i>0;i--){
            vector<int> temp;
            for(int j=n-1;j>=0;j--){
                if((i>>j)&1){
                    temp.push_back(j);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
