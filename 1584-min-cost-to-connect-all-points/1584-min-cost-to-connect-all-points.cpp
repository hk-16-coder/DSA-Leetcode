class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq; 
        // <cost , node>
        pq.push({0,0});

        vector<int> vis(V,0);
        int cost = 0;

        while(!pq.empty()){
            int point = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(vis[point]) continue;
            vis[point] = 1;
            cost+=wt;
            for(int i = 0 ; i<V ; i++){
                if(i == point) continue;

                if(!vis[i]){
                    int dist = abs(points[i][0] - points[point][0]) + abs(points[i][1] -points[point][1]);
                    pq.push({dist,i});
                }
            }
        }
        return cost;
    }
};