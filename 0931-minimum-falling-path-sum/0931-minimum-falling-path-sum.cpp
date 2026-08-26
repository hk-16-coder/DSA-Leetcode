class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n , vector<int>(n));
        for(int i = 0 ; i<n ; i++) dp[0][i] =  matrix[0][i];

        for(int i = 1 ; i<n ; i++){
           for(int j = 0 ; j<n ; j++){
             int top = dp[i-1][j];

             int left = INT_MAX;
             int right = INT_MAX;

             if(j>0) left = dp[i-1][j-1];
             if(j<n-1) right = dp[i-1][j+1];

             dp[i][j] = matrix[i][j] + min(top,min(left,right));
           }
        }
        
        int ans = INT_MAX;

        for(int i = 0 ; i<n ; i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};