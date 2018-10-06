class Rank {
public:
    vector<int> getRankOfNumber(vector<int> A, int n) {
        // write code here
        vector<int> temp;
        for(int i=0;i<n;i++){
            int left = 0,right = i-1;
            while(left<=right){
                int mid = (left+right)/2;
                while(temp[mid]==A[i]) mid++;
                if(temp[mid]<A[i]) left = mid+1;
                else eight =mid-1;
            }
        }
    }
};
