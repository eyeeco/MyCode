class Solution {
public:
    struct Trie{
        string s;
        Trie* node[26];
        Trie(){
            memset(node,0,sizeof(node));
        }
        void insert(string str) {
            Trie* p = this;
            for (int i=0;i<str.size();i++) {
                int pos = str[i]-'a';
                if(!p->node[pos]){
                    p->node[pos] = new Trie();
                }
                p = p->node[pos];
            }
            p->s = str;
        }
    };
    void dfs(vector<vector<char>>& board, vector<string>& res, Trie* root, int i, int j){
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()&&board[i][j]!='#'&&root->node[board[i][j] - 'a']){
            int pos = board[i][j]-'a';
            root = root->node[pos];
            if(!root->s.empty()){
                res.push_back(root->s);
                root->s.clear();
            }
            board[i][j] = '#';
            dfs(board,res,root,i-1,j);
            dfs(board,res,root,i+1,j);
            dfs(board,res,root,i,j-1);
            dfs(board,res,root,i,j+1);
            board[i][j] = 'a'+ pos;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        vector<string> res;
        for(int i=0;i<words.size();i++){
            root->insert(words[i]);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,res,root,i,j);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
