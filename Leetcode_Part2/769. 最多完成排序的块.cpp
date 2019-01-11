class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res=0, n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], arr[i]);
        }
        for(int i=n-2; i>=0; i--) {
            right[i]= min(right[i+1], arr[i]);
        }
        for(int i=0; i<arr.size()-1; i++) {
            if(left[i]<right[i+1]) res++;
        }
        return res+1;
    }
};
