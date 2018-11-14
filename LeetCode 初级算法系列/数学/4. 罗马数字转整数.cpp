class Solution {
public:
    int romanToInt(string s) {
        map<char,int> hash={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int sum = 0;
        for(int i=0;i<s.size();i++){
            if(i==s.size()-1||hash[s[i]]>=hash[s[i+1]]) sum+=hash[s[i]];
            else sum-= hash[s[i]];
        }
        return sum;
    }
};
