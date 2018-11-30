class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash;
        int res = 0;
        for(int num:nums){
            if(!hash[num]){
                int left = hash[num-1]?hash[num-1]:0;
                int right = hash[num+1]?hash[num+1]:0;
                int tmp = left + right +1;
                res = max(res,tmp);
                hash[num] = left+right+1;
                if(hash[num-1]) hash[num-left] = tmp;
                if(hash[num+1]) hash[num+right] = tmp;
            }
        }
        return res;
    }
};
