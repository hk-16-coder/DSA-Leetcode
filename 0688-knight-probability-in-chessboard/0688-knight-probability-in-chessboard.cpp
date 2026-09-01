class Solution {
public:
    vector<vector<int>> move = {{-2,-1} , {-2,1} , {2,-1} , {2,1} , {-1,-2} , {-1,2} , {1,-2} , {1,2}};
    
    double f(int moves , int row , int col , int n , vector<vector<vector<double>>>& dp){
        if(row<0 || row>=n || col<0 || col>=n) return 0;
        if(moves == 0) return 1;
        
        if(dp[moves][row][col] != -1) return dp[moves][row][col]; 
        
        
        double prob = 0;
        for(int i = 0 ; i<8 ; i++){
            int newR = row +  move[i][0];
            int newC = col + move[i][1];

            prob += f(moves-1 , newR , newC , n,dp);
        }
        return dp[moves][row][col] =  prob/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1 , vector<vector<double>>(n,vector<double>(n,-1)));
        return f(k,row,column,n,dp);
    }
};