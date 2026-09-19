class Solution {
public:
    int f(int i , int  j , vector<vector<int>> & matrix , vector<vector<int>>& dp){
        int m = matrix.size();
        int n = matrix[0].size();

        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int left = 1 , right = 1 , up = 1 , down = 1;

        if(i+1<m && matrix[i+1][j] > matrix[i][j]) up = 1 + f(i+1,j , matrix , dp);
        if(i-1>=0 && matrix[i-1][j] > matrix[i][j]) down = 1 + f(i-1,j , matrix , dp);
        if(j+1<n && matrix[i][j+1] > matrix[i][j]) right = 1 + f(i,j+1 , matrix , dp);
        if(j-1 >=0 && matrix[i][j-1] > matrix[i][j]) left = 1 + f(i,j-1 , matrix , dp);

        return dp[i][j] = max(up , max(down , max(right , left)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        int maxi = 0;

        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                int path = f(i , j , matrix , dp);
                maxi = max(maxi , path);
            }
        }
        return  maxi;
    }
};