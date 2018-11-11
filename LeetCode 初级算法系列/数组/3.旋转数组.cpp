class Solution {
public:
    void reverse(vector<int>& nums, int start,int end){
        int mid = (start+end)/2;
        for(int i=start;i<=mid;i++){
            int temp = nums[i];
            nums[i] = nums[start+end-i];
            nums[start+end-i] = temp;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        if(k==0) return ;
        int m = len-k;
        reverse(nums,0,m-1);
        reverse(nums,m,len-1);
        reverse(nums,0,len-1);
    }
};
