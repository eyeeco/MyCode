class Solution {
public:
	void reverseWords(string &s) {
		reverse(s.begin(), s.end());
		int store = 0;
		for (int i = 0; i<s.size(); i++) {
			if (s[i] != ' '){
				if (store != 0) s[store++] = ' ';
				int j = i;
				while (j < s.size() && s[j] != ' ') { s[store++] = s[j++]; }
				reverse(s.begin() + store - (j - i), s.begin() + store);
				i = j;
			}
		}
		s.erase(s.begin() + store, s.end());
	}
};
