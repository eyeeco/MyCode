class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> con(10);
        dfs(res, temp, con, 0, k, n);
        return res;
    }
    void dfs (vector<vector<int>>& res, vector<int>& temp, vector<int>& con, int sum, int k, int n) {
        if (temp.size()==k) {if(sum==n) res.push_back(temp); return ;}
        if (sum>n) return ;
        int i = temp.empty()?0:temp.back();
        for (; i<9; i++) {
            if(!con[i]){
                con[i]++;
                temp.push_back(i+1);
                dfs(res, temp, con, sum+i+1, k, n);
                temp.pop_back();
                con[i]--;
            }
        }
    }
};
