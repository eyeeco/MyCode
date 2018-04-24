class Solution {
public:
    int rectCover(int number) {
        vector<int> res(max(number+1,3),0);
        res[1]=1;res[2]=2;
        for(int i=3;i<=number;i++){
        res[i]=res[i-1]+res[i-2];
        }
        return res[number];
    }
};
