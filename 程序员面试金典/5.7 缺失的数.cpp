class Finder {
public:
    int findMissing(vector<vector<int> > numbers, int n) {
        for(int i=0;i<numbers.size();i++){
            if(i%2!= numbers[i][0]) return i;
        }
        return n;
    }
};
