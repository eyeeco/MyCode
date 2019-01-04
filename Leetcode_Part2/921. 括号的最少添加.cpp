class Solution {
public:
    int minAddToMakeValid(string S) {
        int a=0, b=0;
        for (int i=0; i<S.size(); i++) {
            if (S[i]=='(') {
                a++;
            }else if (a>0) {
                a--;
            }else
                b++;
        }
        return a+b;
    }
};
