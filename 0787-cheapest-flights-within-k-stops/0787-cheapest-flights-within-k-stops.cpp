class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : flights){
           adj[it[0]].push_back({it[1] , it[2]});
        }

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq; // <price , {node,stops}>
       
        pq.push({0,{src,0}});
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX)); // <node,stops>
        dist[src][0] = 0;

        while(!pq.empty()){
            int cost = pq.top().first;
            int node = pq.top().second.first;
            int stops = pq.top().second.second;
            pq.pop();

            if(node == dst) return cost;
            if(stops>k) continue;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int fare = it.second;
                
                if(cost + fare < dist[adjNode][stops+1]){
                    if(stops<=k){
                        dist[adjNode][stops+1] = cost + fare;
                        pq.push({cost+fare , {adjNode,stops+1}});
                    }
                }
            }
        }
       return -1;
    }
};