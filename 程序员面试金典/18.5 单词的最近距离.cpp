class Distance {
public:
    int getDistance(vector<string> article, int n, string x, string y) {
        // write code here
        int pos_x = -1, pos_y = -1;
        int ins = n;
        for(int i=0;i<article.size();i++){
            if(article[i]==x){
                pos_x = i;
                if(pos_y>=0) ins = min(ins,abs(pos_x-pos_y));
            }
            if(article[i]==y){
                pos_y = i;
                if(pos_x>=0) ins = min(ins,abs(pos_x-pos_y));
            }
        }
        return ins;
    }
};
