class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> from(256,-1), to(256,-1);
        if(s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            if (from[s[i]] == -1) {
                if (to[t[i]] == -1) {
                    from[s[i]] = t[i];
                    to[t[i]] = 1;
                } else
                    return false;
            } else if (from[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
