class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
        vector<vector<int>> res;
        vector<int> temp;
        int n;
        for(int i=0;i<ope.size();i++){
            if(ope[i][0]==1){
                if(temp.size() != size-1){
                    temp.push_back(ope[i][1]);
                }else{
                    temp.push_back(ope[i][1]);
                    res.push_back(temp);
                    temp.clear();
                }
            }else{
                if(temp.size() != 0){
                    temp.pop_back();
                }else{
                    n = res.size();
                    temp = res[n-1];
                    temp.pop_back();
                    res.pop_back();
                }
            }
        }
        if(temp.size()!=0) res.push_back(temp);
        return res;
    }
};
