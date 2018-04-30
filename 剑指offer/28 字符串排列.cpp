class Solution {
public:
    void per(set<string> &un_set,string& str,int i){
        if(i==str.size()-1) un_set.insert(str) ;
        else{
            for(int j=i;j<str.size();j++){
                swap(str[i],str[j]);
                per(un_set,str,i+1);
                swap(str[i],str[j]);
            }
        }
    }
    vector<string> Permutation(string str) {
        vector<string> res;
        set<string> un_set;
        per(un_set,str,0);
        for(auto i : un_set) res.push_back(i);
        return res;
    }
};
