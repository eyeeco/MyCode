class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> con(words.size());
        int sum = 0;
        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<words[i].size(); j++) {
                con[i] = 1<<(words[i][j]-'a') | con[i];
            }
        }
        for(int i=0; i<words.size(); i++) {
            for(int j=i+1; j<words.size(); j++) {
                if((con[i]&con[j]) == 0) {
                    int len = words[i].size()*words[j].size();
                    sum = max(sum, len);
                }
            }
        }
        return sum;
    }
};
