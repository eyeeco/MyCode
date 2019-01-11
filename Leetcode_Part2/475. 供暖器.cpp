class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        sort(heaters.begin(), heaters.end());
        for(int i=0; i<houses.size(); i++) {
            auto it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            int pos = INT_MAX;
            if(it!=heaters.end()) pos = abs(houses[i]-*it);
            if(it!=heaters.begin())  pos = min(abs(*(it-1)-houses[i]), pos);
            res = max(res, pos);
        }
        return res;
    }
};
