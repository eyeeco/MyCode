class Render {
public:
    vector<int> renderPixel(vector<int> screen, int x, int y) {
        for(int i=x;i<=y;i++){
            screen[i/8] |= (1<< i%8);
        }
        return screen;
    }
};
