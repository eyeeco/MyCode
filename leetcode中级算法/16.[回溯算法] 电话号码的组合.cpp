class Solution {
public:
    void insertletter(vector<string>& res,string digits,vector<string> dic,string& con,int n){
        if(con.size()==digits.size()){
            res.push_back(con);
        }else{
            string item = dic[digits[n]-'2'];
            for(int i=0;i<item.size();i++){
                con.push_back(item[i]);
                insertletter(res,digits,dic,con,n+1);
                con.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> dic = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string con;
        if(digits.size()==0) return res;
        insertletter(res,digits,dic,con,0);
        return res;
    }
};
