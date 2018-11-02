class Change {
private:
    vector<string> findstring(string s){
        vector<string> res;
        for(int i=0;i<s.size();i++){
            for(char w = 'a';w<='z';w++){
                if(s[i]!=w){
                    string str = s;
                    str[i] = w;
                    res.push_back(str);
                }
            }
        }
        return res;
    }
public:
    int countChanges(vector<string> dic, int n, string s, string t) {
        // write code here;
        set<string> con;
        set<string> visSet;
        queue<string> action;
        map<string,string> back;
        action.push(s);
        for(string str:dic){
            con.insert(str);
        }
        while(!action.empty()){
            string sq = action.front();
            action.pop();
            for(string v: findstring(sq)){
                if(v.compare(t)==0){
                    int num = 0;
                    back[v] = sq;
                    while(back.count(v)&&v!=s){
                        num++;
                        v = back[v];
                    }
                    return num;
                }
                if(con.count(v)){
                    if(!visSet.count(v)){
                        action.push(v);
                        visSet.insert(v);
                        back[v] = sq;
                    }
                }
            }
        }
        return -1;
    }
};
