class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> dic(128,0);
        for(auto c:t) dic[c]++;
        int len = INT_MAX,start = 0, begin = 0, end = 0, count=t.size();
        while(end<s.size()){
            if(dic[s[end++]]-->0) count--;
            while(count==0){
                if(end-begin<len){
                    len = end - begin;
                    start = begin;
                }
                if(dic[s[begin++]]++==0) count++;
            }
        }
        return len!=INT_MAX?s.substr(start,len):"";
    }
};
