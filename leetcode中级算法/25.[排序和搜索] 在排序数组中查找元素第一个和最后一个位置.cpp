class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left =0,right = nums.size()-1;
        int mid ;
        vector<int> res;
        if(!nums.size()) return vector<int>{-1,-1};
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]==target) break;
            else if(nums[mid]<target) left = mid+1;
            else right = mid-1;
        }
        if(left>right) return vector<int>{-1,-1};
        left = mid;
        right = mid;
        while(left>=1&&nums[left]==nums[left-1]) left--;
        while(right<nums.size()-1&&nums[right]==nums[right+1]) right++;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};
