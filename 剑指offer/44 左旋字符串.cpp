class Solution {
public:
    void Inverse(string &str,int start,int end){
        while(start<end){
            swap(str[start],str[end]);
            start++;
            end--;
        }
    }
    string LeftRotateString(string str, int n) {
        if(n==0||str.size()==0) return str;
        Inverse(str,0,n-1);
        Inverse(str,n,str.size()-1);
        Inverse(str,0,str.size()-1);
        return str;
    }
};
