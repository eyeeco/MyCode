class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> table(26);
        string res;
        for(char s:licensePlate){
            if(s>='A'&&s<='Z') table[s-'A']++;
            else if(s>='a'&&s<='z') table[s-'a']++;
        }
        for(string str:words){
            vector<int> temp(table);
            for(char s:str){
                temp[s-'a']--;
            }
            if(isEmp(temp)&&(res.empty()||str.size()<res.size())) res = str;
        }
        return res;
    }
    bool isEmp(vector<int> con){
        for(int i=0; i<con.size(); i++){
            if(con[i]>0) return false;
        }
        return true;
    }
};
