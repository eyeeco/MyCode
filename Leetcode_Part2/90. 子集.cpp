class Solution {
public:
    void dfs(set<vector<int>>& res, vector<int>& nums, vector<int>& temp, vector<int>& visit) {
        res.insert(temp);
        if(temp.size() == nums.size()) return ;
        for (int i=0; i<nums.size(); i++) {
            if (temp.empty() || !visit[i] && nums[i]>=temp.back()) {
                visit[i]++;
                temp.push_back(nums[i]);
                dfs(res, nums, temp, visit);
                temp.pop_back();
                visit[i]--;
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> rs;
        vector<int> temp;
        vector<int> visit(nums.size());
        dfs(res, nums, temp, visit);
        for (auto item:res) rs.push_back(item);
        return rs;
    }
};
