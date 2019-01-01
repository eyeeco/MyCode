/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int sum = 0;
        for (int i=0; i<points.size(); i++) {
            int same = 1, vertical = 1;
            map<pair<int, int>, int> con;
            for (int j=i+1; j<points.size(); j++) {
                if(points[i].x == points[j].x && points[i].y == points[j].y) same++;
                else if (points[i].x == points[j].x) vertical++;
                else {
                    int a = points[i].x - points[j].x;
                    int b = points[i].y - points[j].y;
                    int gcd = GCD(a,b);
                    a/=gcd;
                    b/=gcd;
                    con[make_pair(a,b)]++;
                }
            }
            int local = 0;
            for (auto num : con) {
                local = max(local, num.second);
            }
            local += same;
            local = max(local, vertical);
            sum = max(sum, local);
        }
        return sum;
    }
    int GCD(int a, int b) {
        if(b==0) return a;
        else return GCD(b,a%b);
    }
};
