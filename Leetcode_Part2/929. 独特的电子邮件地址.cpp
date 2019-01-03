class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> con;
        for (string num:emails) {
            string temp;
            int pos = num.find('@');
            for(int it=0; it<pos; it++){
                if(num[it]=='.') continue;
                else if(num[it]=='+') break;
                temp.push_back(num[it]);
            }
            temp.insert(temp.size(),num.substr(pos));
            con.insert(temp);
        }
        return con.size();
    }
};
