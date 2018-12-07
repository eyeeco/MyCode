class UF{
public:
    vector<int> id;
    vector<int> sz;
    int count;

    UF(int m){
        count = 0;
        for(int i=0;i<m;i++){
            id.push_back(i);
            sz.push_back(1);
        }
    }
    int find(int m){
        while(id[m]!=m) m = id[m];
        return m;
    }
    bool connect(int m,int n){
        return find(m)==find(n);
    }
    void _union(int m,int n){
        m = find(m);
        n = find(n);
        if(sz[m]<sz[n]){
            id[m] = n;
            sz[n]++;
        }else{
            id[n] = m;
            sz[m]++;
        }
        count++;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        UF* uf = new UF(M.size());
        for(int i=0;i<M.size();i++){
            for(int j=0;j<=i;j++){
                if(M[i][j]==1&&!uf->connect(i,j)){
                    uf->_union(i,j);
                }
            }
        }
        return M.size()-uf->count;
    }
};
