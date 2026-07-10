class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt = 1;
        for(int i = 0 ; i<intervals.size() - 1 ; i++){
            for(int j = i+1 ; j<intervals.size() ; j++){
                if(intervals[i][0] > intervals[j][0]) swap(intervals[i],intervals[j]);
                else if(intervals[i][0] == intervals[j][0] && intervals[i][1] < intervals[j][1]) swap(intervals[i],intervals[j]);
            }
        }
        int start = intervals[0][0];
        int end =  intervals[0][1];

        for(int i = 1 ; i<intervals.size() ; i++){
            // if(intervals[i][0] == start && intervals[i][1] >= end) continue;
            if(intervals[i][0] >= start && intervals[i][1] <= end) continue;
            cnt++;
            start = intervals[i][0];
            end = intervals[i][1];
        }
        return cnt;
    }
};