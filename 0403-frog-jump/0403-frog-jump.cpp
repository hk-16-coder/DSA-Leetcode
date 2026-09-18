class Solution {
public:
    bool f(int idx , int k , vector<int>& stones ,  vector<vector<int>>& dp){
        if(idx == stones.size() - 1) return true;
        if(dp[idx][k] != -1) return dp[idx][k];
        int n = stones.size();

        for(int jump = k-1 ; jump<=k+1 ; jump++){
            if(jump<=0) continue;
            int val = stones[idx] + jump;
            int l = idx+1;
            int r = n-1;
            int pos = -1;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(stones[mid] == val){
                    pos = mid;
                    break;
                }
                else if(stones[mid] > val) r = mid-1;
                else l = mid+1;
            }
            if(pos != -1 && f(pos , jump , stones , dp)){
               return dp[idx][k] = true;
            }
        }

        return dp[idx][k] = false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1) return false;
        vector<vector<int>> dp(n , vector<int>(n+1,-1));

        return f(1 , 1 , stones , dp);
    }
};