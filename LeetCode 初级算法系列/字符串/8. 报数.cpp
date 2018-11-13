class Solution {
public:
    string change(string str){
        string s;
        int i=0;
        while(i<str.size()){
            int num = 0;
            while(i<str.size()&&str[i]==str[i+1]){
                i++;
                num++;
            }
            s+= to_string(num+1);
            s+= str[i];
            i++;
        }
        return s;
    };
    string countAndSay(int n) {
        string s = "1";
        for(int i=1;i<n;i++){
            s = change(s);
        }
        return s;
    }
};
