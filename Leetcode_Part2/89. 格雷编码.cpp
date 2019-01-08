class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> con(1);
        int base = 1;
        while(n--){
            int len = con.size();
            for(int i=len-1; i>=0; i--) {
                con.push_back(con[i]+base);
            }
            base*=2;
        }
        return con;
    }
};
