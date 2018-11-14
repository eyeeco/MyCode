class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> temp;
        for(int layer=1;layer<=numRows;layer++){
            temp.clear();
            for(int i=0;i<layer;i++){
                if(i==0||i==layer-1) temp.push_back(1);
                else temp.push_back(res[layer-2][i-1]+res[layer-2][i]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
