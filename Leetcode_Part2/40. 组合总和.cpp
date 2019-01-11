class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, res, temp, 0, target, 0);
        return res;
    }
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& temp, int pos, int target, int sum) {
        if(sum>=target) {
            if(sum==target&&!con.count(temp)) {
                res.push_back(temp);
                con.insert(temp);
            }
            return ;
        }
        for(int i=pos; i<candidates.size(); i++) {
            temp.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, res, temp, i+1, target, sum);
            sum -= candidates[i];
            temp.pop_back();
        }
    }
    set<vector<int>> con;
};
