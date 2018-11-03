class SubMatrix {
public:
    bool task(vector<vector<int> > mat,int x1,int y1,int x2,int y2){
        int flag = mat[x1][y1];
        for(int i=0;i<=x2-x1;i++){
            if(mat[x1][y1+i]!=flag||mat[x1+i][y1]!=flag) return false;
            if(mat[x2][y2-i]!=flag||mat[x2-i][y2]!=flag) return false;
        }
        return true;
    }
    int maxSubMatrix(vector<vector<int> > mat, int n) {
        // write code here
        for(int k=0;k<n;k++){
            for(int i=0;i<=k;i++){
                for(int j=0;j<=k;j++){
                    if(task(mat,i,j,i+n-1-k,j+n-1-k)) return n-k;
                }
            }
        }
        return false;
    }
};
