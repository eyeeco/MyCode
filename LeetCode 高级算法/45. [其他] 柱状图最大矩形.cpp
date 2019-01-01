class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return large(heights, 0, heights.size()-1);
    }
    int large(vector<int>& heights, int left, int right) {
        if(left>right) return 0;
        int sum = 0, min_n=left, min_v=heights[left];
        for (int i=left;i<=right;i++) {
            if(heights[i]<min_v){
                min_n = i; min_v = heights[i];
            }
        }
        sum = min_v * (right-left+1);
        sum = max(sum, large(heights, left, min_n-1));
        sum = max(sum, large(heights, min_n+1, right));
        return sum;
    }
};
