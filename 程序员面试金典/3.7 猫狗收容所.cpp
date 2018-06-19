class CatDogAsylum {
public:
    vector<int> asylum(vector<vector<int> > ope) {
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;
        vector<int> res;
        for(int i=0;i<ope.size();i++){
            if(ope[i][0]==1){
                if(ope[i][1]>0){
                    q1.push(make_pair(i,ope[i][1]));
                }else{
                    q2.push(make_pair(i,ope[i][1]));
                }
            }else{
                if(ope[i][1]>0){
                    if(!q1.empty()){
                        res.push_back(q1.front().second);
                        q1.pop();
                    }
                }
                else if(ope[i][1]==0){
                    if(q1.empty()||q2.empty()){
                        if(!q1.empty()){
                            res.push_back(q1.front().second);
                            q1.pop();
                        }
                        if(!q2.empty()){
                            res.push_back(q2.front().second);
                            q2.pop();
                        }
                    }else{
                        if(q1.front().first<q2.front().first){
                            res.push_back(q1.front().second);
                            q1.pop();
                        }else{
                            res.push_back(q2.front().second);
                            q2.pop();
                        }
                    }
                }else{
                    if(!q2.empty()){
                        res.push_back(q2.front().second);
                        q2.pop();
                    }
                }
            }
        }
        return res;
    }
};
