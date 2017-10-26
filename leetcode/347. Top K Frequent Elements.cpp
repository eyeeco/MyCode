
class Solution {
public:
    static bool Entitysort(const pair<int,int> &one,const pair<int,int> &two){return one.second>two.second;};
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> hash;
        vector<pair<int,int>> vec;
        vector<int> res;
        for(auto num : nums){
            hash[num]++;
        }
        for(auto it = hash.begin();it!=hash.end();it++){
            vec.push_back(make_pair(it->first,it->second));
        }
        stable_sort(vec.begin(),vec.end(),Entitysort);
        for(int i=0;i<k;i++){
            res.push_back(vec[i].first);
        }
        return res;
    }
};
