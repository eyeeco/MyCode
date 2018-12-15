class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> rs;
        queue<string> sub;
        set<string> visit;
        bool found = 0;
        sub.push(s);
        visit.insert(s);
        while (!sub.empty()) {
            string temp = sub.front();
            sub.pop();
            if(valid(temp)){
                rs.push_back(temp);
                found = 1;
            }
            if (found) continue;
            for (int i=0; i<temp.size(); i++) {
                if (temp[i] != '('&&temp[i] != ')') continue;
                string str = temp.substr(0,i) + temp.substr(i+1);
                if (!visit.count(str)) {
                    sub.push(str);
                    visit.insert(str);
                }
            }
        }
        return rs;
    }
    bool valid(string str){
        int count = 0;
        for (int i=0; i<str.size(); i++) {
            if (str[i] == '(') count++;
            else if (str[i] == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
};
