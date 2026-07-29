class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int> , int>> q;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
            if(mat[i][j] == 0){
                vis[i][j] = 1;
                q.push({{i,j} , 0});
              }
            }
        }

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            ans[i][j] = steps;
            // UP
            if(i>0 && !vis[i-1][j]){
                vis[i-1][j] = 1;
                q.push({{i-1,j} , steps+1});
            }
            // DOWN
            if(i<n-1 && !vis[i+1][j]){
                vis[i+1][j] = 1;
                q.push({{i+1,j} , steps+1});
            }
            // LEFT
            if(j>0 && !vis[i][j-1]){
                vis[i][j-1] = 1;
                q.push({{i,j-1} , steps+1});
            }
            // RIGHT
            if(j<m-1 && !vis[i][j+1]){
                vis[i][j+1] = 1;
                q.push({{i,j+1} , steps+1});
            }
        }
        return ans;
    }
};