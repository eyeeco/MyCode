class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(j!=t.size()){
            if(s[i]==t[j]){i++;j++;}
            else j++;
        }
        return i==s.size();
    }
};

/*
class Solution:
  def isSubsequence(self,s,t):
    t = iter(t)
    return all(c in t for c in s)
*/
