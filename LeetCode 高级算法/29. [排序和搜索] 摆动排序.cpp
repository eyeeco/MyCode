class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        auto mid = nums.begin() + nums.size()/2;
        nth_element(nums.begin(), mid,nums.end());
        int i = 0, left = 0, right = nums.size()-1;
        int m = *mid;
        #define A(i) nums[(1+i*2)%(nums.size()|1)]
        while (i <= right) {
            if (A(i) > m) {
                swap(A(i++), A(left++));
            }
            else if (A(i) < m) {
                swap(A(i), A(right--));
            } else {
                i++;
            }
        }
    }
};
