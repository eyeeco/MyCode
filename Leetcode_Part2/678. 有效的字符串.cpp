class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, cnt = 0;
        for(char it:s){
            if(it=='(') left++;
            else if(it==')'){
                if(left>0) left--;
                else if(cnt>0) cnt--;
                else return false;
            }else cnt++;
        }
        left = 0, cnt = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==')') left++;
            else if(s[i]=='('){
                if(left>0) left--;
                else if(cnt>0) cnt--;
                else return false;
            }else cnt++;
        }
        return true;
    }
};
