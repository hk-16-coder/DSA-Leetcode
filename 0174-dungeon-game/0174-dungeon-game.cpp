class Solution {
public:
    int f(int i , int j  , vector<vector<int>>& dungeon , vector<vector<int>>& dp){
        int m = dungeon.size();
        int n = dungeon[0].size(); 
        if(i==m-1 && j==n-1) return max(1 , 1 - dungeon[i][j]);
        
        if(dp[i][j] != -1) return dp[i][j];
    
        int down = 1e7 , right = 1e7;
        if(i<m-1){
            down = f(i+1 , j , dungeon , dp);
        }    
        if(j<n-1){
            right = f(i , j+1 , dungeon , dp);
        }
        
        int need = min(down , right);

        return dp[i][j] = max(1 , need - dungeon[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m , vector<int>(n,-1));

    
        return f(0 , 0 , dungeon , dp);
    }
};