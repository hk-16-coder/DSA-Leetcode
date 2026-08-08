class Solution {
public:
    int count(int src ,int n ,  vector<vector<pair<int,int>>>& adj , int max_dist){
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq; // <dist,node>
        pq.push({0,src});

        vector<int> dist(n,1e9);
        dist[src] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            if(dis > dist[node] || dis > max_dist) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dis+edW , adjNode});
                }
            }
        }
        int cnt = 0;
        for(int d : dist){
            if(d<=max_dist) cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int mini = 1e9;
        int node = -1;
        for(int i = 0 ; i<n ; i++){
               int cnt = count(i,n,adj,distanceThreshold);
               if(cnt <= mini){
                   mini = cnt;
                   node = i;
               }
        }
        return node;
    }
};