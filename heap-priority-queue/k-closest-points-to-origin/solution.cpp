class Solution {
public:
    int distance(int x , int y){
        return x*x + y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq; // <distance,index>

        for(int i = 0 ; i<points.size() ; i++){
            pq.push({distance(points[i][0] , points[i][1]) , i});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};