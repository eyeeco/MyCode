class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> con;
        int res = 0;
        for(int num:nums){
            con[num]++;
            int temp = 0;
            if(con[num-1]) temp = max(temp, con[num]+con[num-1]);
            if(con[num+1]) temp = max(temp, con[num]+con[num+1]);
            res = max(res, temp);
        }
        return res;
    }
};
