class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0) return 0;
        int i=0,j=rotateArray.size()-1,mid;
        while(i<j){
            if(rotateArray[i]<rotateArray[j]) return rotateArray[i];
            mid = (i+j)/2;
            if(rotateArray[mid]>=rotateArray[i]) i=mid+1;
            else j = mid;
        }
        return rotateArray[i];
    }
};
