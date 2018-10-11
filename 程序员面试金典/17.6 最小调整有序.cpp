class Rearrange {
public:
    vector<int> findSegment(vector<int> A, int n) {
        // write code here
        vector<int> res(2);
        int max = A[0],min = A[n-1];
        for(int i=0;i<n;i++){
            if(A[i]>=max){
                max = A[i];
            }else{
                res[1] = i;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(A[i]<=min){
                min = A[i];
            }else{
                res[0] = i;
            }
        }
        return res;
    }
};
