class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int top = A[0], curr = 0, curr_top = top;
        for(int i=1;i<A.size();i++){
            if(A[i]<curr_top){
                curr = i;
                curr_top = top;
            }else top = max(top,A[i]);
        }
        return curr+1;
    }
};
