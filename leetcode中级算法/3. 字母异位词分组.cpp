class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> hash;
        vector<vector<string>> res;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            hash[temp].push_back(strs[i]);
        }
        for(auto str:hash){
            res.push_back(str.second);
        }
        return res;
    }
};
