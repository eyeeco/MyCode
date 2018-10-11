class Result {
public:
    vector<int> calcResult(string A, string guess) {
        // write code here
        int n = A.size();
        vector<int> temp(2*n);
        vector<int> res(2);
        for(int i=0;i<n;i++){
            if(A[i]==guess[i]) res[0]++;
            else {
                if(A[i]=='R') temp[0]++;
                if(A[i]=='Y') temp[1]++;
                if(A[i]=='G') temp[2]++;
                if(A[i]=='B') temp[3]++;
                if(guess[i]=='R') temp[4]++;
                if(guess[i]=='Y') temp[5]++;
                if(guess[i]=='G') temp[6]++;
                if(guess[i]=='B') temp[7]++;
            }
        }
        for(int i =0;i<n;i++){
            res[1]+= min(temp[i],temp[n+i]);
        }
        return res;
    }
};
