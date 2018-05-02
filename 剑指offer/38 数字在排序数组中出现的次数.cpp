class Solution {
public:
    int findK(vector<int> data, float k){
        int left = 0, right=data.size()-1;
        int mid;
        while(left<=right){
            mid = (left+right)/2;
            if(data[mid] < k) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0) return 0;
        return findK(data,k+0.5)-findK(data,k-0.5);
    }
};
