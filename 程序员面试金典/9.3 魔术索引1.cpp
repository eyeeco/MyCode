class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        int left = 0,right = A.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(mid==A[mid]) return true;
            else if(mid<A[mid]) right = mid-1;
            else left = mid+1;
        }
        return false;
    }
};
