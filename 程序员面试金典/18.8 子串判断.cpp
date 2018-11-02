class Substr {
private:
    struct TrieNode{
        char c;
        struct TrieNode* ptr[26];
        TrieNode(char c): c(c){
            memset(ptr,0,sizeof(ptr));
        }
    };
    void insert(TrieNode* &root, string str){
        TrieNode* p = root;
        for(int i=0;i<str.size();i++){
            int pos = str[i] - 'a';
            if(p->ptr[pos]==NULL){
                p->ptr[pos] = new TrieNode(str[i]);
            }
            p = p->ptr[pos];
        }
    }
    bool find(TrieNode* root, string str){
        for(int i=0;i<str.size();i++){
            int pos = str[i] - 'a';
            if(root->ptr[pos]==NULL) return false;
            root = root->ptr[pos];
        }
        return true;
    }
public:
    vector<bool> chkSubStr(vector<string> p, int n, string s) {
        // write code here
        TrieNode* root =  new TrieNode(0);
        vector<bool> res;
        for(int i=0;i<s.size();i++){
            insert(root,s.substr(i));
        }
        for(int i=0;i<p.size();i++){
            res.push_back(find(root,p[i]));
        }
        return res;
    }
};
