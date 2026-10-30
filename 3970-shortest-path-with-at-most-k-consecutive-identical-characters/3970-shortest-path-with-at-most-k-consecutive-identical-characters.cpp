class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        vector<vector<int>> dist(n , vector<int>(k+1 , INT_MAX));
        dist[0][1] = 0;

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({0,0,1});

        while(!pq.empty()){
            vector<int> cur = pq.top();
            pq.pop();
            int d = cur[0];
            int u = cur[1];
            int r = cur[2];

            if(d > dist[u][r]) continue;

            for(auto it : adj[u]){
                int v = it.first;
                int w = it.second;
                int newr = 1;

                if(labels[u] == labels[v]){
                    newr = r + 1;
                }

                if(newr > k) continue;

                int newd = d + w;
                if(newd < dist[v][newr]){
                    dist[v][newr] = newd;
                    pq.push({newd , v , newr});
                }
            }
        }

        int ans = INT_MAX;
        for(int i = 0 ; i<=k ; i++){
            ans = min(ans , dist[n-1][i]);
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};