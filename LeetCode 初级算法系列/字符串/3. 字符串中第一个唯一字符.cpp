class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> dict(256,-1);
        for(int i=0;i<s.size();i++){
            if(dict[s[i]]==-1)
                dict[s[i]] = i;
            else
                dict[s[i]]=-2;
        }
        int time = s.size();
        for(int i=0;i<dict.size();i++){
            if(dict[i]>=0 && dict[i]<time){
                time = dict[i];
            }
        }
        if(time == s.size()) return -1;
        return time;
    }
};
