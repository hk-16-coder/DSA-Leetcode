class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> merged;
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        int start  = occupiedIntervals[0][0];
        int end = occupiedIntervals[0][1];
        for(int i = 1 ; i<occupiedIntervals.size() ; i++){
            if(occupiedIntervals[i][0]  <=end +1) end = max(end,occupiedIntervals[i][1]);

            else{
                merged.push_back({start,end});
                start = occupiedIntervals[i][0];
                end = occupiedIntervals[i][1];
            }
        }
        merged.push_back({start,end});
        int i = 0;
      
        while(i<merged.size()){
            start = merged[i][0];
            end = merged[i][1];
            if(freeEnd<start) break;
            if(freeStart>start && freeStart<=end){
                if(freeEnd>end){
                    merged[i][1] = freeStart-1;
                    i++;
                }
                else{
                    merged[i][1] = freeStart-1;
                   if(freeEnd!=end){
                       merged.push_back({freeEnd+1,end});
                       sort(merged.begin(),merged.end());
                   }
                    i++;
                }
            }
            else if(freeStart <= start && freeEnd<end){
                merged[i][0] = freeEnd+1;
                if(merged[i][0] == freeEnd) merged[i][0]++;
                i++;
            }
            else if(freeStart <= start && freeEnd>=end) {
                merged.erase(merged.begin()+i);
                
                
            }
            else if(freeStart>end) i++;
        }
        return merged;
    }
};