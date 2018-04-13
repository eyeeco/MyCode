class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res;
        int sum = 0,n=1;
        for(char letter:S) {
            if((sum+widths[letter-'a'])<=100) sum+= widths[letter-'a'];
            else {
                sum = widths[letter-'a'];
                n++;
            }
        }
        res.push_back(n);
        res.push_back(sum);
        return res;
    }
};
