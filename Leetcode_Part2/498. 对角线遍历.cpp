class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return vector<int>();
        int m = matrix.size(), n = matrix[0].size();
        vector<list<int>> con(m+n);
        vector<int> res;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                int t = i + j;
                if(t % 2 == 0) con[t].push_front(matrix[i][j]);
                if(t % 2 == 1) con[t].push_back(matrix[i][j]);
            }
        }
        for(auto buk:con){
            for(int num:buk){
                res.push_back(num);
            }
        }
        return res;
    }
};
