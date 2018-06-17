class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        set<int> row;
        set<int> col;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(row.count(i)||col.count(j)) mat[i][j] = 0;
            }
        }
        return mat;
    }
};
