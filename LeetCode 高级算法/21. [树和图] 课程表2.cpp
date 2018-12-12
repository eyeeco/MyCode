class Solution {
public:
    bool dfs(vector<unordered_set<int>>& graph,vector<bool>& marked,vector<bool>& curr,stack<int>& con,int num){
        if(marked[num]) return false;
        marked[num] = true;
        curr[num] = true;
        for(int item:graph[num]){
            if(curr[item]||dfs(graph,marked,curr,con,item)) return true;
        }
        con.push(num);
        return curr[num] = false;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<bool> marked(numCourses);
        vector<bool> curr(numCourses);
        vector<int> result;
        stack<int> con;
        for(auto item:prerequisites){
            graph[item.second].insert(item.first);
        }
        for(int i=0;i<numCourses;i++){
            if(dfs(graph,marked,curr,con,i)) return result;
        }
        while(!con.empty()){
            result.push_back(con.top());
            con.pop();
        }
        return result;
    }
};
