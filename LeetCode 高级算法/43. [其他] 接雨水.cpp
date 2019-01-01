class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1;
        int max_left = 0, max_right = 0;
        int sum = 0;
        while (left<=right) {
            if(height[left]<=height[right]){
                if(height[left]>=max_left) max_left=height[left];
                else sum += max_left-height[left];
                left++;
            } else {
                if(height[right]>max_right) max_right = height[right];
                sum += max_right-height[right];
                right--;
            }
        }
        return sum;
    }
};
