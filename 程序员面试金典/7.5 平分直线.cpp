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
class Bipartition {
public:
    vector<double> getBipartition(vector<Point> A, vector<Point> B) {
        double x1=0,y1=0,x2=0,y2=0;
        for(int i=0;i<A.size();i++){
            x1 += A[i].x;
            x2 += B[i].x;
            y1 += A[i].y;
            y2 += B[i].y;
        }
        // Assert x1 != x2
        vector<double> res;
        double k = (y2-y1)/(x2-x1);
        res.push_back(k);
        res.push_back(y1/4-k*x1/4);
        return res;
    }
};
