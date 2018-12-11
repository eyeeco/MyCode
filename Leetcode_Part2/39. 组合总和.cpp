class Solution {
public:
    void combo(vector<int>& candidates,set<vector<int>>& res,vector<int> temp, int pos, int target){
        if(target==0) res.insert(temp);
        int i = 0;
        while(pos<candidates.size()&&candidates[pos] * i <= target){
            int t1 = i, t2=i;
            while(t1--) temp.push_back(candidates[pos]);
            combo(candidates,res,temp,pos+1,target-candidates[pos] * i );
            while(t2--) temp.pop_back();
            i++;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<vector<int>> op;
        vector<int> temp;
        combo(candidates,res,temp,0,target);
        for(auto elem:res) op.push_back(elem);
        return op;
    }
};
