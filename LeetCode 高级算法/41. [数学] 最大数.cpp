class Solution {
public:
    static bool compare(string a, string b) {
        string str1 = a+b;
        string str2 = b+a;
        return str1 > str2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> con;
        for(int num:nums){
            con.push_back(to_string(num));
        }
        sort(con.begin(), con.end(), compare);
        string res;
        for(int i=0; i<con.size(); i++){
            res += con[i];
        }
        while(res.front()=='0' && res.size()>1)
            res.erase(res.begin());
        return res;
    }
};
