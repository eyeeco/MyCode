class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        int temp=1;
        for(int i=0;i<A.size();i++){
            B.push_back(temp);
            temp*=A[i];
        }
        temp = 1;
        for(int i=B.size()-1;i>=0;i--){
            B[i] *= temp;
            temp*=A[i];
        }
        return B;
    }
};
