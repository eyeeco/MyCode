class Frequency {
public:
    int getFrequency(vector<string> article, int n, string word) {
        // write code here
        return count(article.begin(),article.end(),word);
    }
};
