class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n =  grid[0].size();
        vector<vector<int>> vis(m , vector<int>(n,-1));

        int i = 0 , j = 0 , prev_i = 0 , prev_j = 0;
        while(i<m && i>=0 && j<n && j>=0 && vis[i][j] == -1){
            prev_i = i; prev_j = j;
            vis[i][j] = 1;
             
            if(grid[i][j] == 'L'){
                j = j-1;
            }

            else if(grid[i][j] == 'R'){
                j = j+1;
            }

            else if(grid[i][j] == 'U'){
                i = i-1;
            }

            else i = i+1;
        }

        return {prev_i,prev_j};
    }
};