class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first>b.first || (a.first==b.first && a.second < b.second);
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<pair<int, int>> res;
        for (auto item:people) {
            res.insert(res.begin()+item.second,item);
        }
        return res;
    }
};
