class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left=0, right=A.size()-1;
        while (left<=right) {
            int mid = left+ (right-left)/2;
            if(A[mid]>A[mid-1] && A[mid]>A[mid+1]) return mid;
            else if(A[mid]<=A[mid+1]) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};
