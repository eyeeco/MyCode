class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> dict;
        for(char ch : s){
            dict[ch]++;
        }
        for(char ch:t){
            dict[ch]--;
        }
        for(auto ch:dict){
            if(ch.second!=0) return false;
        }
        return true;
    }
};
