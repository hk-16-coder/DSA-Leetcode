class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(n<=2 || m<=2) return;
        queue<pair<int,int>> q;
       
        for(int i = 0 ; i<m ; i++){
            if(grid[0][i] == 'O') {
                q.push({0,i});
                grid[0][i]  = '#';
                }
            if(grid[n-1][i] == 'O'){
                q.push({n-1,i});
                grid[n-1][i] = '#';
                } 
        }

        for(int i = 0 ; i<n ; i++){
            if(grid[i][0] == 'O'){
                q.push({i,0});
                grid[i][0] = '#';
                }
            if(grid[i][m-1] == 'O'){
                q.push({i,m-1});
                grid[i][m-1] = '#';
                } 
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            
            if(row>0 && grid[row-1][col] == 'O'){
                q.push({row-1,col}); // UP
                grid[row-1][col] = '#';
            }
            if(row<n-1 && grid[row+1][col] == 'O'){
                q.push({row+1,col});  // DOWN
                grid[row+1][col] = '#';
                }
            if(col>0 && grid[row][col-1] == 'O'){
                q.push({row,col-1}); // LEFT
                grid[row][col-1] = '#';
                }
            if(col<m-1 && grid[row][col+1] == 'O'){
                q.push({row,col+1}); // RIGHT
                grid[row][col+1] = '#';
                }
        }
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 'O') grid[i][j] = 'X';
                else if(grid[i][j] == '#') grid[i][j] = 'O';
            }
        }
    }
};