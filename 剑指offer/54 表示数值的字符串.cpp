class Solution {
public:
    bool isNumeric(char* string)
    {
        bool sign=false, hasE=false, hasdot=false;
        for(int i=0;i<strlen(string);i++){
            if(string[i]=='+'||string[i]=='-'){
                if(i>0&&string[i-1]!='E'&&string[i-1]!='e') return false;
            }else if(string[i]=='e'||string[i]=='E'){
                if(i==strlen(string)-1) return false;
                if(hasE) return false;
                hasE = true;
            }else if(string[i]=='.'){
                if(hasE||hasdot) return false;
                hasdot = true;
            }else if(string[i] <'0' || string[i] >'9')
                return false;
        }
        return true;
    }

};
