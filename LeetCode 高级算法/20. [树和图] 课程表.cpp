class Solution {
public:
    bool dfs(vector<unordered_set<int>>& graph,vector<bool>& marked,vector<bool>& onstack,int i){
        if(marked[i]) return false;
        marked[i] = onstack[i] = true;
        for(int num:graph[i]){
            if(onstack[num]||dfs(graph,marked,onstack,num)){
                return true;
            };
        };
        onstack[i] = false;
        return false;
    }

    bool dfs2(vector<unordered_set<int>>& graph,vector<bool>& marked,vector<bool>& onstack,int i){
        if(onstack[i]) return true;
        marked[i] = onstack[i] = true;
        for(int num:graph[i]){
            if(!marked[num]&&dfs(graph,marked,onstack,num)){
                return true;
            };
        };
        onstack[i] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<bool> marked(numCourses);
        vector<bool> onstack(numCourses);
        for(auto item:prerequisites){
            graph[item.second].insert(item.first);
        }
        for(int i=0;i<numCourses;i++){
            if(!marked[i]&&dfs2(graph,marked,onstack,i)) return false;
        }
        return true;
    }
};
