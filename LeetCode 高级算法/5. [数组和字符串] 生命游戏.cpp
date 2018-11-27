class Solution {
public:
    int getNum(vector<vector<int>> cp,int i,int j){
        if(i>=0&&i<cp.size()&&j>=0&&j<cp[0].size()){
            if(cp[i][j]) return 1;
        }
        return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>cp(board);
        for(int i=0;i<cp.size();i++){
            for(int j=0;j<cp[0].size();j++){
                int sc = getNum(cp,i-1,j-1)+getNum(cp,i-1,j)+getNum(cp,i-1,j+1)+getNum(cp,i,j-1)+getNum(cp,i,j+1)+getNum(cp,i+1,j-1)+getNum(cp,i+1,j)+getNum(cp,i+1,j+1);
                if(cp[i][j]){
                    if(sc<2||sc>3) board[i][j] = 0;
                    else board[i][j] = 1;
                }else if(sc==3) board[i][j] = 1;
            }
        }
    }
};
