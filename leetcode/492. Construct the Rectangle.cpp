class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> vec;
        int m = sqrt(area);
        if(area==0) return vec;
        while(area%m) m--;
        vec.push_back(area/m);
        vec.push_back(m);
        return vec;
    }
};
