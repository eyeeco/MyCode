class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if(numRows==1) return s;
        for(int i=0;i<numRows;i++){
            int cd = 2*numRows-2 - 2*i;
            int begin = i;
            if(begin==0||begin==numRows-1){
                while(begin<s.size()){
                    res+= s[begin];
                    begin+= 2*numRows-2;
                }
            }else{
                while(begin<s.size()){
                    res+=s[begin];
                    begin+= cd;
                    if(begin>=s.size()) break;
                    res+=s[begin];
                    begin+=2*i;
                }
            }
        }
        return res;
    }
};
