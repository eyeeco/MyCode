/*
struct Point {
    int x;
    int y;
    Point() :
            x(0), y(0) {
    }
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};*/
class DenseLine {
public:
    vector<double> getLine(vector<Point> p, int n) {
        map<pair<double,double>,int> line;
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                double k = (double)(p[j].y-p[i].y)/(p[j].x-p[i].x);
                double b = (double)p[i].y - k * p[i].x ;
                line[make_pair(k,b)]++;
            }
        }
        pair<double,double> res;
        int max_num = 0;
        for(auto el:line){
            if(el.second>max_num){
                res = el.first;
                max_num = el.second;
            }
        }
        vector<double> result;
        result.push_back(res.first);
        result.push_back(res.second);
        return result;
    }
};
