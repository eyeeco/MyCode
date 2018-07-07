class CrossLine {
public:
    bool checkCrossLine(double s1, double s2, double y1, double y2) {
        return !(s1==s2&&y1!=y2);
    }
};
