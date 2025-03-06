class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& visited, int color){
        if(visited[node] == 0){
            visited[node] = color;
            color = (color == 2 ? 1 : 2);
            for(int i : graph[node]) if(!dfs(graph, i, visited, color)) return false;
            return true;
        }
        else return visited[node] == color;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        //i will do dfs 
        //dfs will have a color 2 - red, 1 - blue and node num if node i s already visited it will return else it will mark the node color and continue if it finds inconsistency it will return false;
        vector<int> visited(graph.size());
        for(int i = 0; i < graph.size(); i++){
            //bug fix 1 it may be disconnected
            if(visited[i] == 0 && !dfs(graph, i, visited, 1)) return false;
        }
        return true;
    }
};