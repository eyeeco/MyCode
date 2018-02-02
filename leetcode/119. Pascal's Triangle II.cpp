class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        res[0] = 1;
        for(int round=1;round<=rowIndex;round++){
            for(int i=round;i>0;i--){
                if(i>0) res[i]+=res[i-1];
            }
        }
        return res;
    }
};
