class WordDictionary {
public:
    WordDictionary* dic[26];
    bool word_end;
    /** Initialize your data structure here. */
    WordDictionary():word_end(false) {
        memset(dic, 0, sizeof(dic));
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* pt = this;
        for (int i=0; i<word.size(); i++) {
            int pos = word[i] - 'a';
            if (pt->dic[pos]) {
                pt = pt->dic[pos];
            } else {
                pt->dic[pos] = new WordDictionary();
                pt = pt->dic[pos];
            }
        }
        pt->word_end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_helper(this,0, word);
    }

    bool search_helper(WordDictionary* pt, int k, string word) {
        if(k == word.size()) return pt->word_end;
        if(word[k]!='.'){
            return pt->dic[word[k]-'a'] && search_helper(pt->dic[word[k]-'a'],k+1,word);
        }else{
            for(int i=0;i<26;i++){
                if(pt->dic[i]&&search_helper(pt->dic[i],k+1,word)) return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
