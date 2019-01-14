class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        set<vector<int>> con;
        int k = s1.size();
        if(k>s2.size()) return false;
        vector<int> temp(26);
        vector<int> dict(26);
        for(int i=0; i<k; i++) {
            temp[s1[i]-'a']++;
            dict[s2[i]-'a']++;
        }
        for(int i=k; i<s2.size(); i++) {
            if(equal(temp, dict)) return true;
            dict[s2[i-k]-'a']--;
            dict[s2[i]-'a']++;
        }
        if(equal(temp, dict)) return true;
        return false;
    }
    bool equal(vector<int> v1, vector<int> v2) {
        for(int i=0; i<v1.size(); i++) {
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};
