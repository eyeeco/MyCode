// 自己的写的方法，复杂度较高
class Solution {
public:
    bool isvalid(string str){
        for(int i=0;i<str.size()/2;i++){
            if(str[i]!=str[str.size()-i-1]) return false;
        }
        return true;
    }
    void split(vector<vector<string>>& res,string& s, int num){
        if(num==s.size()) return ;
        if(num==0){
            vector<string> temp;
            string t;
            t.push_back(s[num]);
            temp.push_back(t);
            res.push_back(temp);
        }else{
            vector<vector<string>> temp;
            for(int i=0;i<res.size();i++){
                string t;
                vector<string> str = res[i];
                int len = str.size();
                // single
                t.push_back(s[num]);
                if(isvalid(res[i][len-1])){
                    res[i].push_back(t);
                    temp.push_back(res[i]);
                }
                // union
                str[len-1].push_back(s[num]);
                if(num!=s.size()-1||isvalid(str[len-1]))
                temp.push_back(str);
            }
            res = temp;
        }
        split(res,s,num+1);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        split(res,s,0);
        return res;
    }
};
// 效率较高的解
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        dfs(res,temp,s,0);
        return res;
    }
    void dfs(vector<vector<string>>& res,vector<string>& temp,string s,int curr){
        if(curr>=s.size()){
            res.push_back(temp);
            return ;
        }
        for(int i=curr;i<s.size();i++){
            if(isvalid(s,curr,i)){
                temp.push_back(s.substr(curr,i-curr+1));
                dfs(res,temp,s,i+1);
                temp.pop_back();
            }
        }
    }
    bool isvalid(string s,int left,int right){
        while(left<right){
            if(s[left++]!=s[right--]){
                return false;
            }
        }
        return true;
    }
};
