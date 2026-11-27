class Solution {
public:

    int f(int i , int budget , vector<int>& free , vector<vector<int>>& items , vector<vector<int>>& dp){
        int n = items.size();
        if(i == n) return 0;
        if(budget <  0) return INT_MIN;

        if(dp[i][budget] != -1) return dp[i][budget];

        int pick = INT_MIN , pickMore = INT_MIN;
        if(budget >= items[i][1]){
            pick = 1 + free[i] +  f(i+1 ,  budget - items[i][1] , free , items , dp);
            pickMore = 1 + f(i , budget - items[i][1] , free , items , dp);
        }

        int notPick = f(i+1 , budget , free , items , dp);

        return dp[i][budget] = max(notPick , max(pick , pickMore));
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> free(n);

        for(int i = 0 ; i<n ; i++){
            int cnt = 0;
            for(int j = 0 ; j<n ; j++){
                if(j == i) continue;
                if(items[j][0] % items[i][0] == 0) cnt++;
            }
            free[i] = cnt;
        }

        vector<vector<int>> dp(n , vector<int>(budget+1 , -1));
        return f(0 , budget , free , items , dp);
    }
};