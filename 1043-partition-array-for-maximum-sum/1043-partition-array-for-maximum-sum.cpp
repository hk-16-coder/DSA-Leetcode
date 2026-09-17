class Solution {
public:
    int f(int idx , int k , vector<int>& arr , vector<int>& dp){
        if(idx == arr.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int maxi = 0;
        for(int cut = idx ; cut<idx+k ; cut++){
            if(cut == arr.size()) break;
            int max_val = 0;
            for(int i = idx ; i<=cut ; i++) max_val = max(max_val , arr[i]);

            int sum = (cut - idx + 1) * max_val + f(cut+1 , k , arr , dp);
            maxi = max(maxi , sum);
        }

        return dp[idx] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() , -1);
        return f(0 , k , arr , dp);
    }
};