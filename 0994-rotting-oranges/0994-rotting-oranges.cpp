class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh = 0;
        vector<vector<int>> vis(n , vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q; // <{row,column},time>
        int total = 0;
        for(int i =  0 ; i<n  ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else if(grid[i][j] == 1) cntFresh++;
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int row  = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            total = max(total,time);
            // UP
            if(row>0 && !vis[row-1][col] && grid[row-1][col] == 1){
                q.push({{row-1,col} , time+1});
                vis[row-1][col] = 2;
                cnt++;
            }
            // DOWN
            if(row<n-1 && !vis[row+1][col] && grid[row+1][col] == 1){
                q.push({{row+1,col} , time+1});
                vis[row+1][col] = 2;
                cnt++;
            }
            // RIGHT
            if(col<m-1 && !vis[row][col+1] && grid[row][col+1] == 1){
                q.push({{row,col+1} , time+1});
                vis[row][col+1] = 2;
                cnt++;
            }
            // LEFT
            if(col>0 && !vis[row][col-1] && grid[row][col-1] == 1){
                q.push({{row,col-1} , time+1});
                vis[row][col-1] = 2;
                cnt++;
            }
        }
        if(cnt!=cntFresh) return -1;
        return total;
    }
};