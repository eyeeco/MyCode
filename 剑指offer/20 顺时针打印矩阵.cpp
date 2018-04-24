class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int col = matrix.size();
        int row = matrix[0].size();
        int left = 0,right =row-1,top = 0,bottom = col-1;
        while(left<=right&&top<=bottom){
            for(int i=left;i<=right;i++) res.push_back(matrix[top][i]);
            for(int i=top+1;i<=bottom;i++) res.push_back(matrix[i][right]);
            if(top!=bottom)for(int i=right-1;i>=left;i--) res.push_back(matrix[bottom][i]);
            if(left!=right)for(int i=bottom-1;i>=top+1;i--) res.push_back(matrix[i][left]);
            top++;bottom--;left++;right--;
        }
        return res;
    }
};
