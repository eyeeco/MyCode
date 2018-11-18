static int is_sync = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int patition(vector<int>& nums, int start, int end){
        int l = start, r = end;
        int pivot = nums[l];
        while(l<r){
            while(l<r&&nums[r]>=pivot) r--;
            while(l<r&&nums[l]<=pivot) l++;
            swap(nums[l],nums[r]);
        }
        swap(nums[start],nums[l]);
        return l;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int l = 0, r = len-1;
        while(l<=r){
            int pos = patition(nums,l,r);
            if(pos==len-k) return nums[pos];
            else if(pos<len-k){
                l = pos+1;
            }else{
                r = pos-1;
            }
        }
        return -1;
    }
};
