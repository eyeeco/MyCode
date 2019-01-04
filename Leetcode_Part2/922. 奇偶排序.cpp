class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int p1 = 0, p2 = 1, len = A.size();
        while (p1<len && p2<len) {
            while (p1<len&&A[p1]%2==0) p1+=2;
            while (p2<len&&A[p2]%2==1) p2+=2;
            if(p1<len && p2<len)swap(A[p1], A[p2]);
            p1+=2;
            p2+=2;
        }
        return A;
    }
};
