class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if(len1 > len2) return findMedianSortedArrays(nums2,nums1);
        int start = 0, end = len1, half = (len1+len2+1)/2;
        while (start <= end) {
            int i = (start + end)/2;
            int j = half - i;
            if (i < len1 && nums1[i] < nums2[j-1]) {
                start = i+1;
            }else if (i > 0 && nums1[i-1] > nums2[j]) {
                end = i-1;
            } else {
                int left_max, right_min;
                if (i==0) left_max = nums2[j-1];
                else if (j==0) left_max = nums1[i-1];
                else left_max = max(nums1[i-1],nums2[j-1]);
                if ((len1+len2)%2==1) return left_max;
                if (i==len1) right_min = nums2[j];
                else if(j==len2) right_min = nums1[i];
                else right_min = min(nums1[i],nums2[j]);
                return ((float)left_max+right_min)/2;
            }
        }
    }
};
