class Solution {
public:
    vector<string> getWords(string s){
        vector<string> res;
        for(int i=0;i<s.size();i++){
            for(char t='a';t<='z';t++){
                if(s[i]!=t){
                    string str = s;
                    str[i] = t;
                    res.push_back(str);
                }
            }
        }
        return res;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> con;
        queue<string> act;
        set<string> visit;
        unordered_map<string,string> back;
        act.push(beginWord);
        for(string s:wordList){
            con.insert(s);
        }
        while(!act.empty()){
            string curr = act.front();
            act.pop();
            for(string str:getWords(curr)){
                if(con.count(str)&&str.compare(endWord)==0){
                    int count = 0;
                    back[str] = curr;
                    while(back[str].compare(beginWord)){
                        str = back[str];
                        count++;
                    }
                    return count+2;
                }
                if(con.count(str)&&!visit.count(str)){
                    visit.insert(str);
                    back[str] = curr;
                    act.push(str);
                }
            }
        }
        return 0;
    }
};
