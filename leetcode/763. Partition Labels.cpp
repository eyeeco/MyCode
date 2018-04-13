class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last(26,0);
        vector<int> res;
        int j = 0,tip=0;
        for(int i=0;i<S.size();i++) last[S[i]-'a']=i;
        for(int i=0;i<S.size();i++){
            j = max(j,last[S[i]-'a']);
            if(i==j){
                res.push_back(i-tip+1);
                tip = i+1;
            }
        }
        return res;
    }
};
