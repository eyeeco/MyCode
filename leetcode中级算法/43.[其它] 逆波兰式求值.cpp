class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> con;
        for(string str:tokens){
            if(str=="+"||str=="-"||str=="*"||str=="/"){
                int a = con.top();
                con.pop();
                int b = con.top();
                con.pop();
                if(str=="+") con.push(b+a);
                if(str=="-") con.push(b-a);
                if(str=="*") con.push(b*a);
                if(str=="/") con.push(b/a);
            }else{
                con.push(atoi(str.c_str()));
            }
        }
        return con.top();
    }
};
