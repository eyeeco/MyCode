class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, len_s = s.size(), len_p = p.size();
        int pos_star = -1, pos_match = -1;
        while (i < len_s){
            if (j < len_p && (s[i] == p[j] || p[j] == '?')) {
                i++; j++; continue;
            }
            if (j < len_p && p[j] == '*') {
                pos_star = j; j++; pos_match = i; continue;
            }
            if (pos_star >=0) {
                j = pos_star + 1; i = ++pos_match; continue;
            }
            return false;
        }
        while (j < len_p) {
            if (p[j++] != '*') return false;
        }
        return true;
    }
};
