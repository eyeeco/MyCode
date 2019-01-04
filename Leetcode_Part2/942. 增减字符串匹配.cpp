class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        int left = 0, right = S.size();
        for (int i=0; i<S.size(); i++) {
            if (S[i]=='I') res.push_back(left++);
            else res.push_back(right--);
        }
        res.push_back(left);
        return res;
    }
};
