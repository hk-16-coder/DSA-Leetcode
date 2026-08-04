class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n==1) return grid[0][0] == 0 ? 1 : -1; 
        vector<vector<int>> vis(n, vector<int>(n,0));

        queue<pair<pair<int,int> , int>> q; // {row,col} , nodes visited
        q.push({{0,0},1});
        vis[0][0] = 1;
        int dist = INT_MAX;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int nodes = q.front().second;
            q.pop();

            for(int i = -1 ; i<2 ; i++){
                for(int j = -1 ; j<2 ; j++){
                    if(i==0 && j==0) continue;
                    int nRow = row + i;
                    int nCol = col + j;
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<n && !vis[nRow][nCol] && grid[nRow][nCol] == 0){
                        q.push({{nRow,nCol} , nodes+1});
                        vis[nRow][nCol] = 1;
                        if(nRow == n-1 && nCol == n-1) return nodes+1;
                    }
                }
            }
        }
       return -1;
    }
};