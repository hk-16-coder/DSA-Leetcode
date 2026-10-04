class Solution {
public:
    int zeros = 1;
    int ans = 0;
    void f(int i , int j , int cnt , vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == -1) return;

        if(grid[i][j] == 2){
            if(cnt == zeros){
                ans++;
            }
            return;
        }

        grid[i][j] = -1;

        f(i+1 , j , cnt + 1 , grid);
        f(i , j+1 , cnt + 1 , grid);
        f(i-1 , j , cnt + 1 , grid);
        f(i , j-1 , cnt + 1 , grid);

        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> start(2);
        

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    start[0] = i;
                    start[1] = j; 
                }

                if(grid[i][j] == 0){
                    zeros++;
                }
            }
        }
        
        f(start[0] , start[1] , 0 , grid);
        return ans;
    }
};