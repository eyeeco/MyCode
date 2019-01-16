class Solution {
public:
    static bool cmp(string a, string b) {
        if(a.size()!=b.size()) return a.size()<b.size();
        else return a<b;
    }
    string longestWord(vector<string>& words) {
        unordered_set<string> con;
        sort(words.begin(), words.end(), cmp);
        int num = 0;
        string temp;
        for(int i=0; i<words.size(); i++) {
            int len = words[i].size();
            if(len==1||con.count(words[i].substr(0,len-1))||con.count(words[i].substr(1))) {
                con.insert(words[i]);
                if(len>num) {
                    num = len;
                    temp = words[i];
                }
            }
        }
        return temp;
    }
};
