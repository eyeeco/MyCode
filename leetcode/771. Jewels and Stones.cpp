class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> s;
        int sum = 0;
        for(char num : J){
            s.insert(num);
        }
        for(char num : S){
            if(s.count(num)>0) sum++;
        }
        return sum;
    }
};
