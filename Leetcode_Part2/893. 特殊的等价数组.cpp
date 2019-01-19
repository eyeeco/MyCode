class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<vector<int>> con;
        for(int i=0; i<A.size(); i++) {
            vector<int> word(52);
            for(int j=0; j<A[i].size(); j++) {
                int pos;
                if(j%2==0) {
                    pos = A[i][j] - 'a';
                } else {
                    pos = A[i][j] - 'a' + 26;
                }
                word[pos]++;
            }
            con.insert(word);
        }
        return con.size();
    }
};
