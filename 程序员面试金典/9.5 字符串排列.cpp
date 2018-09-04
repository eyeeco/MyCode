class Permutation {
public:
    string insertWord(string word,int j,char s){
        string front = word.substr(0,j);
        string end = word.substr(j);
        return front + s + end;
    }
    vector<string> getPermutations(string A) {
        vector<string> temp;
        vector<string> wlist;
        if(A.size()==0){
            string str = "";
            temp.push_back(str);
            return temp;
        }
        char s = A[0];
        wlist = getPermutation(A.substr(1));
        for(auto word : wlist){
            for(int j=0;j<=word.size();j++){
                string str = insertWord(word,j,s);
                temp.push_back(str);
            }
        }
        return temp;
    }
    vector<string> getPermutation(string A) {
        vector<string> res = getPermutations(A);
        sort(res.begin(),res.end(),[](string a,string b){return a>b;});
        return res;
    }
};
