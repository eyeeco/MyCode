class Solution {
public:
    void dfs(vector<vector<int>> graph,vector<vector<int>> &paths,vector<int> path,int node,int end){
        path.push_back(node);
        if(node == end){
            paths.push_back(path);
            return ;
        }
        for(int i : graph[node]){
            dfs(graph,paths,path,i,end);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<vector<int>> paths;
        vector<int> path;
        if(N==0) return paths;
        dfs(graph,paths,path,0,N-1);
        return paths;
    }
};
