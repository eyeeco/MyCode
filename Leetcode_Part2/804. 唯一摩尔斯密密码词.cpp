class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> con;
        for (int i=0; i<words.size(); i++) {
            string temp;
            for (int j=0; j<words[i].size(); j++) {
                int pos = words[i][j] - 'a';
                temp += code[pos];
            }
            con.insert(temp);
        }
        return con.size();
    }
};
