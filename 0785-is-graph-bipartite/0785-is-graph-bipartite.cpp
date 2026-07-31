class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<int> color(n,-1);
        
        for(int i = 0 ; i<n ; i++){
            if(color[i] == -1){
                if(!dfs(i , 0 , color , graph)) return false;
            }
        }
        return true;
    }
    bool dfs(int node , int clr ,vector<int>& color , vector<vector<int>>& graph){
        color[node] = clr;
        for(auto it : graph[node]){
            if(color[it] == -1){
                if(!dfs(it,1-clr,color,graph)) return false;
            }
            else if(color[it] == clr) return false; // adjacent nodes have same color
        }
        return true;
    }
};