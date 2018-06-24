class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        return n|(m<<j);
    }
};
