class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<len;i++){
            for(int j=0;j<len/2;j++){
                swap(matrix[i][j],matrix[i][len-1-j]);
            }
        }
    }
};
