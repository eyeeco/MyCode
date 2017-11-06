class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_num=INT_MAX,count=0;
        for(auto num: nums) if(num<min_num) min_num=num;
        for(auto num: nums) count+=(num-min_num);
        return count;
    }
};