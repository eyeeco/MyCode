class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2=INT_MAX;
        for(int num:nums){
            if(num<=m1) m1 = num;
            else if(num<=m2) m2 = num;
            else return true;
        }
        return false;
    }
};
