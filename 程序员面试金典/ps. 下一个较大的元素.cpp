class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        stack<int> repo;
        vector<int> res(n);
        repo.push(-1);
        for(int i=n-1;i>=0;i--){
            while(repo.top()!=-1&&A[i]>=repo.top()) repo.pop();
            res[i] = repo.top();
            repo.push(A[i]);
        }
        return res;
    }
};
