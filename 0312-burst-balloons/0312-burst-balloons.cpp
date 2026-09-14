class Solution {
public:
    int f(int i , int j , vector<int>& nums , vector<vector<int>>& dp){
        if(j - i == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 0;

        for(int k = i+1 ; k<j ; k++){
            int score = nums[i] * nums[k] * nums[j] + f(i , k , nums , dp) + f(k , j , nums , dp);
            maxi = max(maxi , score); 
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin() , 1);
        int n = nums.size();

        vector<vector<int>> dp(n , vector<int>(n,-1));
        return f(0 , n-1 , nums , dp);
    }
};