class MagicIndex {
public:
    bool magic(vector<int> A,int left,int right){
        if(left>right) return false;
        int mid = (left+right)/2;
        if(mid == A[mid]) return true;
        else{
            int rightEnd = min(mid-1,A[mid]);
            int leftEnd = max(mid+1,A[mid]);
            return magic(A,left,rightEnd) | magic(A,leftEnd,right);
        }
    }
    bool findMagicIndex(vector<int> A, int n) {
        return magic(A,0,n-1);
    }
};
