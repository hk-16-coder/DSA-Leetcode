class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        if(n<=2 || m<=2) return cnt;
        queue<pair<int,int>> q;
       
        for(int i = 0 ; i<m ; i++){
            if(grid[0][i] == 1) {
                q.push({0,i});
                grid[0][i]  = '#';
                }
            if(grid[n-1][i] == 1){
                q.push({n-1,i});
                grid[n-1][i] = '#';
                } 
        }

        for(int i = 0 ; i<n ; i++){
            if(grid[i][0] == 1){
                q.push({i,0});
                grid[i][0] = '#';
                }
            if(grid[i][m-1] == 1){
                q.push({i,m-1});
                grid[i][m-1] = '#';
                } 
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            
            if(row>0 && grid[row-1][col] == 1){
                q.push({row-1,col}); // UP
                grid[row-1][col] = '#';
            }
            if(row<n-1 && grid[row+1][col] == 1){
                q.push({row+1,col});  // DOWN
                grid[row+1][col] = '#';
                }
            if(col>0 && grid[row][col-1] == 1){
                q.push({row,col-1}); // LEFT
                grid[row][col-1] = '#';
                }
            if(col<m-1 && grid[row][col+1] == 1){
                q.push({row,col+1}); // RIGHT
                grid[row][col+1] = '#';
                }
        }
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 1) cnt++;
               
            }
        }
        return cnt;
    }
};