class Solution {
public:
    void dfs(int node , vector<vector<int>>& adj , vector<int>& vis){
                vis[node] = 1;
                for(auto it : adj[node]){
                    if(vis[it] == 0) dfs(it,adj,vis);
                }
    } 
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);
        for(auto it : invocations){
            adj[it[0]].push_back(it[1]);
        }

        vector<int> vis(n,0);
        dfs(k,adj,vis);
        // mark all suspicious nodes 
        // NOW WE CHECK ALL EDGES
        for(int u = 0 ; u<n ; u++){
            for(int v : adj[u]){

                if(!vis[u] && vis[v] == 1){
                    // CANNOT REMOVE SUS METHODS
                    vector<int> ans;
                    for(int i = 0 ; i<n ; i++) ans.push_back(i);
                    return ans;
                }
            }
        }

        // NOW WE CAN REMOVE SUS METHODS
        vector<int> ans;
        for(int i = 0 ; i<n ; i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};