// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNum(long long left,long long right){
        int mid = (left+right)/2;
        int res = guess(mid);
        if(res==0) return mid;
        if(res>0) return guessNum(mid+1,right);
        else return guessNum(1,mid-1);
    }
    int guessNumber(int n) {
        return guessNum(1,n);
    }
};
