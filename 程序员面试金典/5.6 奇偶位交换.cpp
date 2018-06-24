class Exchange {
public:
    int exchangeOddEven(int x) {
        // write code here
        return ((x&0xaaaaaaaa)>>1)|((x&0x55555555)<<1);
    }
};
