class Solution {
public:
    bool isNum(char s){
        return s-'0'>=0&&s-'0'<=9;
    }
    int myAtoi(string str) {
        int i=0;
        int len = 0;
        int w = 1;
        long long sum = 0;
        if(i>=str.size()) return sum;
        while(str[i]==' '){
            i++;
        }
        if(i>=str.size()) return sum;
        if(str[i]=='+'){
            i++;
        }else if(str[i]=='-'){
            w = -1;
            i++;
        }
        if(i>=str.size()||!isNum(str[i])) return sum;
        while(i<str.size()&&isNum(str[i])){
            if(sum!=0) len++;
            sum = sum*10 + str[i]-'0';
            i++;
        }
        if(len>10||sum>INT_MAX){
            if(w>0) return INT_MAX;
            else return INT_MIN;
        }
        return sum*w;
    }
};
