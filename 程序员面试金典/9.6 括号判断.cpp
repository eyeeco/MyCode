class Parenthesis {
public:
    bool adjust(char a, char b){
        return a=='('&&b==')';
    }
    bool chkParenthesis(string A, int n) {
        stack<char> s;
        for(char item : A){
            if(s.empty()||!adjust(s.top(),item)) s.push(item);
            else{
                s.pop();
            }
        }
        return s.empty();
    }
};
