class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        long long  sum = 0;
        int maxi = INT_MIN;
        int ans = -1;
        for(int i = 0 ; i<n ; i++){
            sum += weights[i];
            maxi = max(maxi,weights[i]);
        }
        long long  low = maxi;
        long long high = sum;
        while(low<=high){
            long long mid = low + (high-low)/2;
            int temp_days = 0;
            int temp_sum = 0;
            for(int i = 0 ; i<n ; i++){
                if(temp_sum+weights[i] <= mid){
                    temp_sum+=weights[i];
                } 
                else{
                    temp_days++;
                    temp_sum = weights[i];
                }
            }
            temp_days+=1;
            if(temp_days>days) low = mid + 1;
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};