class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x^y;
        int num = 0;
        while(t){
            t = t&(t-1);
            num++;
        }
        return num;
    }
};
