class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int , double>> adj[n]; // <node , probability>
        
        for(int i = 0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1] , succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0] , succProb[i]});
        } 

        vector<double> prob(n,0);
        prob[start_node] = 1;

        priority_queue<pair<double,int>> pq ; // MAX-HEAP <prob,node>
        pq.push({1,start_node});

        while(!pq.empty()){
            int node = pq.top().second;
            double probly = pq.top().first;
            pq.pop();

            if(probly < prob[node]) continue;

            if(node == end_node) return probly;
            for(auto it : adj[node]){
                int adjNode = it.first;
                double edW = it.second;

                if(probly*edW > prob[adjNode]){
                    prob[adjNode] = probly*edW;
                    pq.push({probly*edW , adjNode});
                }
            }
        }
        return 0;
    }
};