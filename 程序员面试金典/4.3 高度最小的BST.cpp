class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        int size = vals.size();
        int height = 1;
        while(!(pow(2,height-1)<=size && size<=pow(2,height)-1)){
            height++;
        }
        return height;
    }
};
