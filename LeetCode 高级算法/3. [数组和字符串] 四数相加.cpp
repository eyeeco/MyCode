class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,int> dic;
        int num = 0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                dic[-(A[i]+B[j])]++;
            }
        }
        for(int i=0;i<C.size();i++){
            for(int j=0;j<D.size();j++){
                if(dic.count(C[i]+D[j])){
                    num+=dic[C[i]+D[j]];
                }
            }
        }
        return num;
    }
};
