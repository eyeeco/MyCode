class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
        int left = 0,right = A.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(A[mid]==x) return mid;
            else if(A[mid]<A[right]){
                if(A[mid]<=x && x<=A[right]) left = mid+1;
                else right = mid-1;
            }else{
                if(A[left]<=x && x<=A[mid]) right = mid-1;
                else left = mid+1;
            }
        }
        return 0;
    }
};
