class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        int order = 0;
        for(int i=0;i<len;i++){
            order += (s[len-i-1]-'A'+1) * pow(26,i);
        }
        return order;
    }
};
