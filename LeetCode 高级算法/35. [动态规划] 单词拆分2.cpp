class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> con;
        unordered_set<string> dic;
        for (string str:wordDict) {
            dic.insert(str);
        }
        return word(s,dic,con);
    }
    vector<string> word(string s, unordered_set<string>& dic, unordered_map<string, vector<string>>& con) {
        if (con.count(s)) return con[s];
        vector<string> res;
        if(dic.count(s)) res.push_back(s);
        for (int i=1; i<s.size(); i++) {
            string str = s.substr(i);
            if (dic.count(str)) {
                string temp = s.substr(0, i);
                vector<string> pre = combine(word(temp,dic,con),str);
                res.insert(res.end(),pre.begin(),pre.end());
            }
        }
        con[s] = res;
        return res;
    }
    vector<string> combine(vector<string> pre, string str) {
        for (int i=0; i<pre.size(); i++) {
            pre[i] += " "+str;
        }
        return pre;
    }
};
