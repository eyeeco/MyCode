class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<int> alphbet(58,10001);
        int  t ;
        if(str.size()==0) return -1;
        for(int i=0;i<str.size();i++){
            t = str[i] - 'A';
            if(alphbet[t]==10001) alphbet[t] = i;
            else alphbet[t] = 10002;
        }
        sort(alphbet.begin(),alphbet.end());
        return alphbet[0];
    }
};
