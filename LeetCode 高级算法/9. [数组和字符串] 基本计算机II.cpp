class Solution {
public:
    int calculate(string s) {
        stack<int> con;
        int num = 0;
        int sign = '+';
        int res = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
                num = num*10 + s[i]-'0';
            }
            if(!(s[i]>='0'&&s[i]<='9')&&s[i]!=' '||i==s.size()-1){
                if(sign=='+') con.push(num);
                else if(sign=='-') con.push(-num);
                else if(sign=='*') {
                    int temp = con.top() * num;
                    con.pop();
                    con.push(temp);
                }
                else if(sign=='/'){
                    int temp = con.top()/ num;
                    con.pop();
                    con.push(temp);
                }
                sign = s[i];
                num = 0;
            }
        }
        while(!con.empty()){
            res += con.top();
            con.pop();
        }
        return res;
    }
};
