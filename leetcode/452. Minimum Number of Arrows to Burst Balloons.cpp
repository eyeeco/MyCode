class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(),points.end(),[](pair<int,int> a,pair<int,int> b){return a.second<b.second;});
        int p = 0, num=0,t;
        while(p<points.size()){
            t = points[p].second;
            while(p<points.size()&&t >= points[p].first) p++;
            num++;
        }
        return num;
    }
};
