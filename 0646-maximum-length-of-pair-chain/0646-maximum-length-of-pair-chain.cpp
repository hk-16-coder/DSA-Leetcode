class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end() , [](vector<int>& arr1 , vector<int>& arr2){
            return arr1[0] < arr2[0];
        });

        int n = pairs.size();
        vector<int> dp(n,1);
        
        int maxi = 0;
        for(int i = 0 ; i<n ; i++){
            for(int prev = 0 ; prev<i ; prev++){
                if(pairs[prev][1] < pairs[i][0] && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};