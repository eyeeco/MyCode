class Solution {
public:
	bool helper(char* matrix, char* str, int rows, int cols, int i, int j, int k, vector<bool> flag){
		int index = i * cols + j;
		if (i<0 || i >= rows || j<0 || j >= cols || matrix[index] != str[k] || flag[index] == 1)
			return false;
		if (k == strlen(str) - 1) return true;
		flag[index] = 1;
		if (helper(matrix, str, rows, cols, i - 1, j, k + 1, flag) ||
			helper(matrix, str, rows, cols, i + 1, j, k + 1, flag) ||
			helper(matrix, str, rows, cols, i, j - 1, k + 1, flag) ||
			helper(matrix, str, rows, cols, i, j + 1, k + 1, flag))
			return true;
		flag[index] = 0;
		return false;
	}
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		vector<bool> flag(rows*cols, 0);
		for (int i = 0; i<rows; i++){
			for (int j = 0; j<cols; j++){
				if (helper(matrix, str, rows, cols, i, j, 0, flag))
					return true;
			}
		}
		return false;
	}

};
