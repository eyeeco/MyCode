class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size();
        int sum =0;
        int left,right;
        for(int i=0;i<2*N-1;i++){
            left = i/2;
            right = (i+1)/2;
            while(left>=0&&right<N&&s[left]==s[right]){
                sum++;
                left--;
                right++;
            }
        }
        return sum;
    }
};
