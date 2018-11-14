class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int t = 0;
        int turn = 31;
        while(turn--){
            if(n%2==1) t+=1;
            n = n>>1;
            t = t<<1;
        }
        if(n%2==1) t+=1;
        return t;
    }
};
