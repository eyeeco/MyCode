class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0) return res;
        int left=0,right=matrix[0].size()-1;
        int top=0,end=matrix.size()-1;
        while(left<=right&&top<=end){
            for(int i=left;i<=right;i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=end;i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if(left>right||top>end) return res;
            for(int i=right;i>=left;i--){
                res.push_back(matrix[end][i]);
            };
            end--;
            for(int i=end;i>=top;i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};
