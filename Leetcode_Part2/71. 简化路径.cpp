class Solution {
public:
    string simplifyPath(string path) {
        int ps=0, pe=1;
        stack<string> con;
        string res;
        while(pe<path.size()){
            while(pe<path.size()&&path[pe]!='/') pe++;
            string it = path.substr(ps+1, pe-ps-1);
            // cout<<it<<endl;
            if(it!=""){
                if(it=="..") {
                    if(!con.empty()) con.pop();
                }
                else if(it!=".") con.push(it);
            }
            ps = pe;
            pe++;
        }
        while(!con.empty()){
            res = '/' + con.top() + res;
            con.pop();
        }
        return res==""?"/":res;
    }
};
