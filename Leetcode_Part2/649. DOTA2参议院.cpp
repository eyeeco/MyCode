class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<int> q1, q2;
        for(int i=0; i<senate.size(); i++){
            if(senate[i]=='R'){
                q1.push_back(i);
            }else{
                q2.push_back(i);
            }
        }
        while(!q1.empty()&&!q2.empty()){
            int r1 = q1.front(), r2 = q2.front();
            q1.pop_front();
            q2.pop_front();
            if(r1<r2) q1.push_back(r1+senate.size());
            else q2.push_back(r2+senate.size());
        }
        return q1.size()>q2.size()?"Radiant":"Dire";
    }
};
