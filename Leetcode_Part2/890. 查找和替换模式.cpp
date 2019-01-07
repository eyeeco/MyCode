class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (int i=0; i<words.size(); i++) {
            if (compare(words[i], pattern)) res.push_back(words[i]);
        }
        return res;
    }
    bool compare(string word, string pattern) {
        if(word.size() != pattern.size()) return false;
        string s2p(26,'#'), p2s(26, '#');
        for(int i=0; i<word.size(); i++){
            int pos_w = word[i]-'a';
            int pos_p = pattern[i]-'a';
            if(s2p[pos_w]=='#') s2p[pos_w] = pattern[i];
            if(p2s[pos_p]=='#') p2s[pos_p] = word[i];
            if(s2p[pos_w]!=pattern[i]) return false;
            if(p2s[pos_p]!=word[i]) return false;
        }
        return true;
    }
};
