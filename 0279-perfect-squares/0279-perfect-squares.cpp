class Solution {
public:
    int f(int idx , int n , vector<int>& arr , vector<vector<int>>& dp){
        if(idx == 0){
            if(n % arr[idx] == 0) return n/arr[idx];
            return 1e9;
        }

        if(dp[idx][n] != -1) return dp[idx][n];

        int notTake = f(idx-1 , n , arr , dp);
        int take = 1e9;
        if(arr[idx] <= n){
            take = 1 + f(idx , n - arr[idx] , arr , dp);
        }

        return dp[idx][n] = min(take,notTake);
    }
    int numSquares(int n) {
        vector<int> arr;
        for(int i = 1 ; i <= sqrt(n) ; i++){
            arr.push_back(i*i);
        }

        int idx = arr.size();
        vector<vector<int>> dp(idx , vector<int>(n+1,-1));
        return f(idx-1,n,arr,dp); 
    }
};