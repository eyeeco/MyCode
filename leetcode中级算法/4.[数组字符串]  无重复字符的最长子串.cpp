class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        for(int i=0;i<s.size();i++){
            int num = 0;
            set<char> dic;
            for(int j=i;j>=0;j--){
                if(dic.count(s[j])){
                    break;
                }else{
                    dic.insert(s[j]);
                    num++;
                }
            }
            res = max(res,num);
        }
        return res;
    }
};
