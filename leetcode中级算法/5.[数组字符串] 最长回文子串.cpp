class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        string res;
        for(int i=0;i<s.size();i++){
            int j=1;
            while(i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j]){
                j++;
            }
            if(2*j-1>max){
                max = 2*j-1;
                res = s.substr(i-j+1,1+2*(j-1));
            }
            int start = i-1,end = i;
            while(start>=0&&end<s.size()&&s[start]==s[end]){
                start--;
                end++;
            }
            if(end-start-1>max){
                max = end -start -1;
                res = s.substr(start+1,end-start-1 );
            }
        }
        return res;
    }
};
