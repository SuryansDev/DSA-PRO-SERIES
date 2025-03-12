class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> drns = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        auto comp = [&](pair<int, int> p1, pair<int, int> p2){return dist[p1.first][p1.second] > dist[p2.first][p2.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> que(comp);

        dist[0][0] = 0;
        que.push({0, 0});

        while(!que.empty()){
            auto currNode = que.top();
            que.pop();

            for(auto & drn : drns){
                int x = currNode.first;
                int y = currNode.second;
                int newX = drn[0] + x;
                int newY = drn[1] + y;

                if(newX >= 0 && newY >= 0 && newX < rows && newY < cols){
                    int newDist = max(abs(heights[newX][newY] - heights[x][y]), dist[x][y]);
                    if(newDist < dist[newX][newY]){
                        dist[newX][newY] = newDist;
                        que.push({newX, newY});
                    }
                }
            }
        }

        return dist[rows - 1][cols - 1];
        //why are we using BFS? we can bfs work here
    }
};