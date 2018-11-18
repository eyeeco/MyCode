class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        vector<pair<int,int>> dic;
        vector<int> res;
        int i=0;
        for(int num:nums){
            hash[num]++;
        }
        for(auto it:hash){
            dic.push_back(make_pair(it.first,it.second));
        }
        sort(dic.begin(),dic.end(),[](pair<int,int> a,pair<int,int> b){return a.second>b.second;});
        while(k--){
            res.push_back(dic[i].first);
            i++;
        }
        return res;
    }
};
