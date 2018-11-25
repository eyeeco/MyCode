class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string con;
        dfs(n,n,con,res);
        return res;
    }
    void dfs(int left, int right, string con, vector<string>& res){
        if(left>right) return ;
        if(left==0&&right==0){
            res.push_back(con);
        }else{
            if(left>0) dfs(left-1,right,con+'(',res);
            if(right>0) dfs(left,right-1,con+')',res);
        }
    }
};
