class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long product = 1LL*m*k;
        if(product > n) return -1;
        int ans = -1;;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0 ; i<n ; i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int low = mini;
        int high = maxi;
        while(low<=high){
            int mid = low + (high - low)/2;
            int temp = 0;
            int cnt = 0;
            for(int i = 0; i<n ; i++){
                if(bloomDay[i]<=mid) cnt++;
                else cnt = 0;
                if(cnt==k) {
                    temp++;
                    cnt = 0;
              }
            }
            if(temp < m) low = mid+1;
            else{
                ans = mid;
                high = mid-1;
            } 
        }
        return ans;
    }
};