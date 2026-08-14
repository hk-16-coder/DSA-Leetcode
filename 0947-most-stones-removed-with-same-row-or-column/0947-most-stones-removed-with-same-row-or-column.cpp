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
    int removeStones(vector<vector<int>>& stones) {
        int stone_cnt = stones.size();
        int row = 0 , col = 0;
        for(auto it : stones){
            row = max(row,it[0]);
            col = max(col,it[1]);
        }

        DSU ds(row+col+1);
        unordered_map<int,int> stoneNodes;

        for(auto it : stones){
            int rowNode = it[0];
            int colNode = it[1] + row + 1;
            ds.unionBySize(rowNode , colNode);

            stoneNodes[rowNode] = 1;
            stoneNodes[colNode] = 1;
        }

        int cnt = 0;
        for(auto it : stoneNodes){
            if(ds.findUpar(it.first) == it.first){
                cnt++;
            }
        }
        return stone_cnt - cnt;
    }
};