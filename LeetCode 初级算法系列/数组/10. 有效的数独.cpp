class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
        cout<<1<<endl;
		for (int i = 0; i<board.size(); i++){
			vector<int> flag(9, 0);
			for (int j = 0; j<board[0].size(); j++){
				if (board[i][j] != '.'){
					int ch = board[i][j] - '1';
					if (flag[ch] == 0)  flag[ch]++;
					else return false;
				}
			}
		};
		for (int i = 0; i<board.size(); i++){
			vector<int> flag(9, 0);
			for (int j = 0; j<board[0].size(); j++){
				if (board[j][i] != '.'){
					int ch = board[j][i] - '1';
					if (flag[ch] == 0)  flag[ch]++;
					else return false;
				}
			}
		};
		for (int i = 0; i<board.size(); i += 3){
			for (int j = 0; j<board[0].size(); j += 3){
				vector<int> flag(9, 0);
				for (int m = 0; m < 3; m++){
					for (int n = 0; n < 3; n++){
						if (board[i + m][j + n] != '.'){
							int ch = board[i + m][j + n] - '1';
							if (flag[ch] == 0) flag[ch]++;
							else return false;
						}
					}
				}
			}
		};
		return true;
	}
};
