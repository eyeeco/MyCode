class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left =0,right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(mid==left) return nums[left]>nums[right]?left:right;
            if(nums[mid]<nums[mid+1]){
                left = mid;
            }else{
                right = mid;
            }
        }
        return -1;
    }
};
