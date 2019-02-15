class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int start = 0, end = 0;
        vector<vector<int>> res;
        while(end<S.size()){
            while(end<S.size()-1&&S[end]==S[end+1]) end++;
            if(end-start>=2) {
                vector<int> temp = {start, end};
                res.push_back(temp);
            }
            end++;
            start = end;
        }
        return res;
    }
};
