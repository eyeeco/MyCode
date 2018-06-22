/*
struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};*/

class Path {
public:
    bool check(UndirectedGraphNode* a, UndirectedGraphNode* b){
        if(a==NULL||b==NULL) return false;
        if(a==b) return true;
        queue<UndirectedGraphNode*> q;
        map<UndirectedGraphNode*,bool> vis;
        q.push(a);
        while(!q.empty()){
            UndirectedGraphNode* temp = q.front();
            vis[temp] = true;
            q.pop();
            for(int i=0;i<temp->neighbors.size();i++){
                if(temp->neighbors[i]==b) return true;
                if(temp->neighbors[i]&&!vis[temp->neighbors[i]]){
                    q.push(temp->neighbors[i]);
                }
            }
        }
        return false;
    }
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        return check(a,b)||check(b,a);
    }
};
