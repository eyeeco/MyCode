class Joseph {
public:
    int getResult(int n) {
        // write code here
        vector<int> res;
        for(int i=1;i<=n;i++){
            res.push_back(i);
        }
        int t = 2;
        while(res.size()>1){
            vector<int> temp;
            temp.push_back(0);
            for(int i=0;i<res.size();i++){
                if((i+1)%t==1) temp.push_back(res[i]);
            }
            temp[0] = temp[temp.size()-1];
            temp.erase(temp.end()-1);
            res = temp;
            t++;
        }
        return res[0];
    }
};
