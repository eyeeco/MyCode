class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        multiset<int> con;
        vector<int> res;
        if(input.size()==0 || k>input.size() || k<=0 ) return res;
        for(int i=0;i<input.size();i++){
            if(con.size()<k) con.insert(input[i]);
            else{
                auto it = con.end();
                it--;
                if(input[i]< *it){
                    con.erase(it);
                    con.insert(input[i]);
                }
            }
        }
        for(auto it=con.begin();it!=con.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};
