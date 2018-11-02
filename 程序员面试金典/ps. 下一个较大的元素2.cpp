//这个题有问题，这不是我写的代码，
//应该是双栈实现

class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        vector<int> repo;
        vector<int> res(n);
        repo.push_back(-1);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<repo.size();j++){
                if(repo[j]==-1||A[i]>repo[j]) break;
            }
            res[i] = repo[j];
            repo.insert(repo.begin()+j,A[i]);
        }
    }
};
