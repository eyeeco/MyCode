class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left =0,right =nums.size()-1,mid;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid%2==1){
                if(nums[mid-1]==nums[mid]) left = mid+1;
                else right = mid-1;
            }else{
                if(nums[mid-1]==nums[mid]) right = mid-1;
                else left = mid+1;
            }
        }
        return nums[mid];
    }
};
