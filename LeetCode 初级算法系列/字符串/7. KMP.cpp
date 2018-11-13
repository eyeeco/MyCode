class Solution {
public:
    int strStr(string haystack, string needle) {
        int q=1,k=0;
        vector<int> next(needle.size());
        if(needle.size()==0) return 0;
        for(q=1,k=0;q<needle.size();q++){
            while(k>0&&needle[q]!=needle[k]){
                k = next[k-1];
            }
            if(needle[k]==needle[q]){
                k++;
            }
            next[q] = k;
        }
        for(int i=0,q=0;i<haystack.size();i++){
            while(q>0&&needle[q]!=haystack[i])
                q = next[q-1];
            if(needle[q]==haystack[i]){
                q++;
            }
            if(q==needle.size()){
                return i-q+1;
            }
        }
        return -1;
    }
};
