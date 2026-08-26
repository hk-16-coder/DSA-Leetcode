class Solution {
public:
    int f(int row , int col , vector<vector<int>>& triangle ,  vector<vector<int>>& dp){
        int n = triangle.size();

        if(dp[row][col] != -1) return dp[row][col];
        if(row == 0) return dp[row][col] =  triangle[0][0];

        if(col == 0) return dp[row][col] =  triangle[row][col] + f(row-1,col,triangle,dp);

        if(col == row) return dp[row][col] =  triangle[row][col] + f(row-1,col-1,triangle,dp);

        int left = f(row-1,col-1,triangle,dp);
        int right = f(row-1,col,triangle,dp);

        return dp[row][col] = triangle[row][col] + min(left,right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i = 0 ; i<n ; i++){
           mini = min(mini , f(n-1,i,triangle,dp));
        }
        return mini;
    }
};