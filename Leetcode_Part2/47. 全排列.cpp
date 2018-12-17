class Solution {
public:
    void trace(vector<int>& nums, set<vector<int>>& rs, vector<int>& pt, vector<int> visit) {
        if (pt.size() == nums.size()) {
            rs.insert(pt);
            return ;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visit[i]){
                visit[i]++;
                pt.push_back(nums[i]);
                trace(nums, rs, pt, visit);
                pt.pop_back();
                visit[i]--;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> rs;
        vector<int> pt;
        vector<int> visit(nums.size());
        trace(nums, rs, pt, visit);
        for(auto item : rs) {
            res.push_back(item);
        }
        return res;
    }
};
