class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        long long sum = 0;
        long long squares = 0;

        int n = grid.size();
        for(int i = 0 ; i<n ;i++){
            for(int j = 0 ; j<n ; j++){
                sum += grid[i][j];
                squares +=  1LL*grid[i][j] * grid[i][j];
            }
        }
        // sum = original_sum - missing + repeat
        // sum_squares = sum_original_squares - missing^2 + repeat^2 
        // now add both
        long long Osum = n*n * (n*n + 1)/2; 
        long long a = (n*n+1)*(2*n*n + 1);
        long long b = n*n;
        long long Osquared =a*b/6 ; 
        long long alpha  = sum - Osum;
        long long beta = squares - Osquared;
        long long rpt = ((beta/alpha) + alpha)/2;
        long long mis = rpt - alpha;
        

         return {int(rpt),int(mis)};
    }
};