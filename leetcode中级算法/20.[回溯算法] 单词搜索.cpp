class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> board, string word, int p, int i, int j){
        if(p==word.size()) return true;
        else if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()&&board[i][j]==word[p]){
            board[i][j] = '-';
            return dfs(board,word,p+1,i-1,j)||dfs(board,word,p+1,i+1,j)||dfs(board,word,p+1,i,j-1)||dfs(board,word,p+1,i,j+1);
        }else
            return false;
    }
};
