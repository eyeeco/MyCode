class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size()) return false;
        vector<int> record;
        vector<int> table(26);
        int flag = 0;
        for(int i=0; i<A.size(); i++){
            if(A[i]==B[i]){
                if(table[A[i]-'a']>0) flag = 1;
                else table[A[i]-'a']++;
            }else{
                record.push_back(i);
            }
        }
        if(record.size()==0&&flag==1) return true;
        if(record.size()==2&&A[record[0]]==B[record[1]]&&A[record[1]]==B[record[0]]) return true;
        return false;
    }
};
