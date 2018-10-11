class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        int n = board.size();
        vector<int> record(2*n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    record[i]++;
                    record[n+j]++;
                }
            }
        }
        for(int i : record){
            if(i==n) return true;
        }
        int i=0,j=0;
        while(i<n&&board[i][i]==1){
            i++;
        }
        while(j<n&&board[j][n-1-j]==1){
            j++;
        }
        return (i==n)||(j==n);
    }
};
