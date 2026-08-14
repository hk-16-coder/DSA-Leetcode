class DSU{
public:
    vector<int> parent,rank,size;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);

        for(int i = 0 ; i<=n ; i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(parent[node] == node) return node;

        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u , int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
              parent[ulp_v] = ulp_u;
        }

        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u , int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
         
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int extra_edges = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUpar(u) == ds.findUpar(v)) extra_edges++;
            else{
                ds.unionBySize(u,v);
            }
        }
        
        int nC = 0; // number of connected components
        for(int i = 0 ; i<n ; i++){
            if(ds.parent[i] == i) nC++;
        }
        // ans = nC-1
        if(extra_edges >= nC-1) return nC-1;
        return -1;
    }
};