class Same {
public:
    bool checkSam(string stringA, string stringB) {
        map<int,int> tab;
        for(int i=0;i<stringA.size();i++){
            tab[stringA[i]]++;
        }
        for(int i=0;i<stringB.size();i++){
            tab[stringB[i]]--;
        }
        for(auto& it:tab){
            if(it.second) return false;
        }
        return true;
    }
};
