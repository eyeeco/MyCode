class Trie {
public:
    Trie* tr[26];
    bool end;
    /** Initialize your data structure here. */
    Trie():end(false){
        memset(tr,0,sizeof(tr));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* pt = this;
        for (int i=0; i<word.size(); i++) {
            int ch = word[i] - 'a';
            if(pt->tr[ch]) {
                pt = pt->tr[ch];
            } else {
                pt->tr[ch] = new Trie();
                pt = pt->tr[ch];
            }
        }
        pt->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* pt = this;
        for (int i=0; i<word.size(); i++) {
            int ch = word[i] - 'a';
            if (pt->tr[ch]) {
                pt = pt->tr[ch];
            } else
                return false;
        }
        return pt->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* pt = this;
        for (int i=0; i<prefix.size(); i++) {
            int ch = prefix[i] - 'a';
            if (pt->tr[ch]) {
                pt = pt->tr[ch];
            } else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
