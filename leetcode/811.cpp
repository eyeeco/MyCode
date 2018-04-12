class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> m;
        vector<string> res;
        for(auto str:cpdomains){
            int i = str.find(" ");
            int n = stoi(str.substr(0,i));
            string s = str.substr(i+1,str.size()-i-1);

            for(int j=s.size()-1;j>=0;j--){
                if(s[j]=='.') m[s.substr(j+1,s.size()-j-1)]+=n;
                else if(j==0) m[s.substr(j,s.size()-j)]+=n;
            }
        }
        for(auto it:m) res.push_back(to_string(it.second)+" "+it.first);
        return res;
    }
};
