class Solution {
public:
    int f(int i , int j , vector<int>& cuts , vector<vector<int>>& dp){
        if(j-i <= 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i+1 ; k<j ; k++){
            int cost = cuts[j] - cuts[i] + f(i, k , cuts ,dp) + f(k , j , cuts , dp); 
            mini = min(mini , cost);
        }

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        
        int s = cuts.size();
        vector<vector<int>> dp(s , vector<int>(s,-1));

        return f(0 , s - 1 , cuts , dp);
    }
};