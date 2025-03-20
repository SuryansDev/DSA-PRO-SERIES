class DisjointSet{
    public:
    int n;
    vector<int> parent;
    vector<int> rank;
    vector<int> andarr;
    //rank by size

    DisjointSet(int n){
        this->n = n;
        parent.resize(n);
        rank.resize(n, 1);
        andarr.resize(n, INT_MAX);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findParent(int i){
        if(parent[i] != i){
            parent[i] = findParent(parent[i]);
        }
        return parent[i];
    }

    void unionSet(int a, int b, int w){
        a = findParent(a);
        b = findParent(b);

        if(a != b){
            if(rank[a] == rank[b]){
                rank[a]++;
                parent[b] = a;
            }
            else if(rank[a] > rank[b]){
                parent[b] = a;
            }
            else {
                parent[a] = b;
            }
        }
        andarr[parent[a]] =(andarr[a] & andarr[b] & w);
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet DJ(n);
        for(auto const & edge : edges){
            DJ.unionSet(edge[0], edge[1], edge[2]);
        }

        vector<int> ans(query.size(), -1);
        for(int i = 0; i < ans.size(); i++){
            if(DJ.findParent(query[i][0]) == DJ.findParent(query[i][1])){
                ans[i] = DJ.andarr[DJ.findParent(query[i][0])];
            }
        }
        return ans;
    }
};