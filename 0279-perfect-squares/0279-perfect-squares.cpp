class Solution {
public:
    int numSquares(int n) {
        int nums = sqrt(n);

        vector<int> curr(n+1) , prev(n+1);
    
        for(int i = 1 ; i<=n ; i++){
            prev[i] = 1e9;
        }

        for(int idx = 1 ; idx<=nums ; idx++){
            for(int T = 1 ; T<=n ; T++){
                int notTake = prev[T];
                int take = 1e9;
                if(idx*idx <= T){
                     take = 1 + curr[T - idx*idx];
                }

               curr[T] = min(take,notTake);
            }
            prev = curr;
        }
        return prev[n];
    }
};