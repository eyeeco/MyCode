class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int h = matrix.size(), w = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[h-1][w-1];
        while (low < high) {
            int mid = low + (high - low)/2;
            int less = count(matrix, mid);
            if (less < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
    int count(vector<vector<int>>& matrix, int num){
        int sum = 0, i = 0, j = matrix.size()-1;
        while (i < matrix.size() && j >=0) {
            if (num >= matrix[i][j]) {
                sum += (j+1);
                i++;
            } else
                j--;
        }
        return sum;
    }
};
