class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> drns = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}};
        if(grid[0][0] == 1) return -1;
        if(grid.size() == 1) return 1;
        queue<pair<int, int>> que;
        que.push({0, 0});

        int dist = 0;
        grid[0][0] = 2;

        while(!que.empty()){
            dist++;
            int nodes = que.size();
            for(int i = 0; i < nodes; i++){
                auto currNode = que.front();
                que.pop();

                for(auto& drn : drns){
                    int newX = currNode.first + drn[0];
                    int newY = currNode.second + drn[1];
                    if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == 0){
                        if(newX == grid.size() - 1 && newY == grid[0].size() -1) return dist + 1;
                        que.push({newX, newY});
                        grid[newX][newY] = 2;
                    } 
                }
            }
        }

        return -1;
    }
};