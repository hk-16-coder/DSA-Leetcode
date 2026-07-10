class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long maxi = INT_MIN;
        for(int i = 0 ; i<n ; i++){
              maxi = max(maxi ,1LL*piles[i]); 
        }
        if(n == h) return (int)maxi;
        if (n==1){
          if(piles[0]%h != 0) return piles[0]/h + 1;
          else return piles[0]/h;
        }

        long long low = 1;
        long long high = maxi;
        long long ans;
        while(low<=high){
            long long mid = low + (high-low)/2;
            long long temp = 0;
            for(int i = 0 ; i<n ;i++){
                if(piles[i]<=mid)temp++;
                else {
                   if(piles[i]%mid != 0) temp+=piles[i]/mid + 1;
                   else temp += piles[i]/mid;
                }
            }
            if(temp <= h) {
                ans = mid;
                high = mid-1;
            }
            else  low = mid+1;
           
        }
        return (int)ans;
    }
};