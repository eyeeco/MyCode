class Transform {
public:
    void swap(vector<vector<int>> &mat,int x1,int y1,int x2,int y2){
         int temp;
         temp = mat[x1][y1];
         mat[x1][y1] = mat[x2][y2];
         mat[x2][y2] = temp;
    }
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat,i,j,j,i);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(mat,i,j,i,n-j-1);
            }
        }
        return mat;
    }
};
