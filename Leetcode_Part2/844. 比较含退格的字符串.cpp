class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;
        for (char item : S) {
            if(item=='#') {
                if(!s.empty()) s.pop();
            } else {
                s.push(item);
            }
        }
        for (char item : T) {
            if(item=='#') {
                if(!t.empty()) t.pop();
            } else {
                t.push(item);
            }
        }
        if(s.size()!=t.size()) return false;
        while (!s.empty()&&!t.empty()) {
            if(s.top()!=t.top()) return false;
            s.pop();
            t.pop();
        }
        return true;
    }
};
