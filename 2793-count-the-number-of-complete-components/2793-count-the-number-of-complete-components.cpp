class DisjointSet{
    public:
    int n;
    vector<int> parent;
    vector<int> rank;
    vector<int> edgeCount;
    //rank by size

    DisjointSet(int n){
        this->n = n;
        parent.resize(n);
        rank.resize(n, 1);
        edgeCount.resize(n, 0);
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

    void unionSet(int a, int b){
        a = findParent(a);
        b = findParent(b);

        if(a != b){
            if(rank[a] > rank[b]){
                parent[b] = a;
                rank[a] += rank[b];
            }
            else {
                parent[a] = b;
                rank[b] += rank[a];
            }
            edgeCount[parent[a]] =(edgeCount[a] + edgeCount[b] + 1);
        }
        else{
            edgeCount[parent[a]] += 1;
        }
        
    }
};


class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet DJ(n);
        for(auto const & edge : edges){
            DJ.unionSet(edge[0], edge[1]);
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(DJ.parent[i] == i){
                int nodes = DJ.rank[i];
                int edges = DJ.edgeCount[i]; 
                if(edges == nodes*(nodes-1)/2) count++;
            }
        }
        return count;
    }
};