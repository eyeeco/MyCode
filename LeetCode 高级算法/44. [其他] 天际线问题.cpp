class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> con;
        for (auto item : buildings) {
            con.push_back(make_pair(item[0], -item[2]));
            con.push_back(make_pair(item[1], item[2]));
        }
        sort(con.begin(), con.end());
        multiset<int> skline = {0};
        vector<pair<int, int>> res;
        int top = 0;
        for (int i=0; i<con.size(); i++) {
            if (con[i].second < 0) {
                skline.insert(-con[i].second);
            } else {
                skline.erase(skline.find(con[i].second));
            }
            if (!skline.empty()&&*skline.rbegin() != top) {
                top = *skline.rbegin();
                res.push_back(make_pair(con[i].first, top));
            }
        }
        return res;
    }
};
