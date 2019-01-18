class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i = 0, l = 0, r = 0;
        unordered_map<char, string> func1;
        unordered_map<string, char> func2;
        while (i<pattern.size()&&l<str.size()) {
            while(r<str.size()&&str[r]!=' ') r++;
            string s = str.substr(l, r-l);
            if(!func1.count(pattern[i])) func1[pattern[i]] = s;
            else if(func1[pattern[i]] != s) return false;
            if(!func2.count(s)) func2[s] = pattern[i];
            else if(func2[s] != pattern[i]) return false;
            r++;
            l = r;
            i++;
        }
        return i == pattern.size() && r == str.size()+1;
    }
};
