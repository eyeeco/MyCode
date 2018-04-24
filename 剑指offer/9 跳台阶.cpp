class Solution {
public:
    int jumpFloor(int number) {
        if(number == 1) return 1;
        if(number == 2) return 2;
        vector<int> res(number,1);
        res[1] = 2;
        for(int i=2;i<number;i++){
            res[i] = res[i-1] + res[i-2];
        }
        return res[number-1];
    }
};
