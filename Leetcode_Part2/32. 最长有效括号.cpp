class Solution {
public:
    int longestValidParentheses(string s) {
        int len = 0;
        stack<int> con;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') {
                con.push(i);
            } else {
                if(!con.empty()&&s[con.top()]=='(') {
                    con.pop();
                } else {
                    con.push(i);
                }
            }
        }
        if(con.empty()) len = s.size();
        else {
            int end = s.size(), start = 0;
            while(!con.empty()) {
                start = con.top();
                con.pop();
                len = max(len, end-start-1);
                end = start;
            }
            len = max(len, start);
        }
        return len;
    }
};
