class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> temp = pairs[0];
        int cnt = 1;
        for(int i=1; i<pairs.size(); i++){
            if(pairs[i][0]>temp[1]){
                temp = pairs[i];
                cnt++;
            }
        }
        return cnt;
    }
    static bool cmp(vector<int> a, vector<int> b){
        return a[1]<b[1] || (a[1]==b[1] && a[0]<b[0]);
    }
};
