class Solution {
public:
    int binaryGap(int N) {
        int dict = 0, count = 0;
        while(N) {
            if(N%2==0&&count>0) {
                count++;
            } else if(N%2==1) {
                dict = max(dict, count);
                count=1;
            }
            N/=2;
        }
        return dict;
    }
};
