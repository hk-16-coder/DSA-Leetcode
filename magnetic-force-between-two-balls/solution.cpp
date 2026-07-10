class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
       sort(position.begin() , position.end());
       int n = position.size();
       if(m == 2) return  position[n-1] - position[0];
       int low = 1;
       int high = position[n-1] - position[0];

       while(low<=high){
        int mid = low + (high-low)/2;
        int cnt = 1;
        int last = position[0];
        for(int i = 1 ; i<n ; i++){
            if(position[i] - last >= mid) {
                cnt++;
                last = position[i];
            }
        }
        if(cnt >=m) low = mid + 1;
        else high = mid-1;
        
       }
       return high;
    }
};