class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> temp(n);
        vector<vector<int>> res(n, temp);
        int i = 0, j = n-1, l = 0, r = n-1;
        int count = 1;
        while (i <= j && l <= r) {
            for (int t = i; t <= j; t++) {
                res[l][t] = count;
                count++;
            }
            l++;
            for (int t = l; t <= r; t++) {
                res[t][r] = count;
                count++;
            }
            j--;
            if(i > j || l > r) break;
            for (int t = j; t>=i; t--) {
                res[r][t] = count;
                count++;
            }
            r--;
            for(int t = r; t>= l; t--) {
                res[t][i] = count;
                count++;
            }
            i++;
        }
        return res;
    }
};
