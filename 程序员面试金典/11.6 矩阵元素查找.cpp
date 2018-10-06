class Finder {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        // write code here
        vector<int> res;
        int i=0,j=m-1;
        while(i<n&&j>=0){
            if(mat[i][j]==x) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
            else if(mat[i][j]<x) i++;
            else j--;
        }
        return res;
    }
};
