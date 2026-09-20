class Solution {
public:
    int f(int idx  , int time , vector<int>& arr , vector<vector<int>>& dp){
        if(idx == arr.size()) return 0;
        if(dp[idx][time] != -1) return dp[idx][time];

        int maxi = 0;
        int cook = time*arr[idx] + f(idx+1 , time+1 , arr , dp);
        int dontCook = f(idx+1 , time , arr , dp);
        maxi = max(maxi , max(cook , dontCook));

        return dp[idx][time] =  maxi;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin() , satisfaction.end());

        vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        return f(0 , 1 , satisfaction , dp);
    }
};