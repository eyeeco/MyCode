class SubMatrix {
public:
    int sumMatrix(vector<int> temp){
        int num = temp[0];
        for(int i=1;i<temp.size();i++){
            temp[i] = max(temp[i-1]+temp[i],temp[i]);
            num = max(num,temp[i]);
        }
        return num;
    }
    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        // write code here
        int sum = mat[0][0];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int> temp(n);
                for(int pos = 0;pos<n;pos++)
                    for(int k=i;k<=j;k++){
                        temp[pos]+=mat[pos][k];
                }
                sum = max(sum,sumMatrix(temp));
            }
        }
        return sum;
    }
};
