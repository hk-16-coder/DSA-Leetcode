class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m , vector<int>(n));
        bool flag = false;
        for(int i = 0 ; i<m ; i++){
            if(matrix[i][0] == '1') {
                dp[i][0] = 1;
                flag = true;
                }
        }

        for(int j = 1 ; j<n ; j++){
            if(matrix[0][j] == '1') {
                dp[0][j] = 1;
                flag = true;
                }
        }

        int maxi = flag; // maxi is max side length
        for(int i = 1 ; i<m ; i++){
            for(int j = 1 ; j<n ; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(dp[i-1][j] , min(dp[i-1][j-1] , dp[i][j-1]));
                    maxi = max(maxi , dp[i][j]);
                }
            }
        }
        return maxi*maxi;
    }
};