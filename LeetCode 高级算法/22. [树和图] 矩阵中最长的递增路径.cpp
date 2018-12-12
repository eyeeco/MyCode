class Solution {
public:
    int path(vector<vector<int>>& matrix,int temp, int i,int j,vector<vector<int>>& cache){
        if(i>=0&&i<matrix.size()&&j>=0&&j<matrix[0].size()&&matrix[i][j]>temp){
            if(cache[i][j]) return cache[i][j];
            cache[i][j]=max(max(path(matrix,matrix[i][j],i-1,j,cache),path(matrix,matrix[i][j],i+1,j,cache)),max(path(matrix,matrix[i][j],i,j-1,cache),path(matrix,matrix[i][j],i,j+1,cache)))+1;
            return cache[i][j];
        }
        return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int count = 0;
        if(matrix.size()==0) return 0;
        vector<int> temp(matrix[0].size(),0);
        vector<vector<int>> cache(matrix.size(),temp);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                count = max(count,path(matrix,INT_MIN,i,j,cache));
            }
        }
        return count;
    }
};
