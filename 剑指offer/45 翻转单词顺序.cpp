class Solution {
public:
    void Inverse(string &str,int start, int end){
        while(start<end){
            swap(str[start],str[end]);
            start++;
            end--;
        }
    }
    string ReverseSentence(string str) {
        Inverse(str,0,str.size()-1);
        int m=0,n=0;
        while(n<str.size()){
            if(str[n] == ' '){
                Inverse(str,m,n-1);
                m = n+1;
            }
            n++;
        }
        Inverse(str,m,str.size()-1);
        return str;
    }
};
