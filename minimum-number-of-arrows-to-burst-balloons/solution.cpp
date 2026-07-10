class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort (points.begin() ,  points.end());
        int end = points[0][1];

        int removed = 0;
        for(int i = 1 ; i<n ; i++){
            if (points[i][0]<=end){
                removed = removed + 1;
                if (points[i][1]<=end){
                    end = points[i][1];
                }
            }
            else{
                end = points[i][1];
            }
        }
        return n - removed;
    }
};