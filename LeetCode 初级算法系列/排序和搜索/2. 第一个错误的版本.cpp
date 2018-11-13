// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 1,right = n;
        while(left<right){
            long long mid = (left+right)/2;
            if(isBadVersion((int)mid)){
                if(mid==1||!isBadVersion(mid-1)){
                    return mid;
                }else{
                    right = mid-1;
                }
            }
            else
                left = mid + 1;
        }
        return left;
    }
};
