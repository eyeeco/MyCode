class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<int> con;
        vector<vector<int>> res;
        for(int i=0; i<points.size(); i++) {
            int dist =  points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(con.size()<K) {
                con.push(dist);
            } else if(dist<con.top()) {
                con.push(dist);
                con.pop();
            }
        }
        int kdist = con.top();
        for(int i=0; i<points.size(); i++) {
            int dist =  points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(dist<=kdist) {
                vector<int> temp;
                temp.push_back(points[i][0]);
                temp.push_back(points[i][1]);
                res.push_back(temp);}
        }
        return res;
    }
};
