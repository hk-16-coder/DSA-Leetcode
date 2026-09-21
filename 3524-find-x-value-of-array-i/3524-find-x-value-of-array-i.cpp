class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k);
        vector<long long> dp(k);

        for(int x : nums){
            int rem = x%k;
            vector<long long> next(k);
            next[rem]++;

            for(int r = 0 ; r<k ; r++){
                next[(r*rem) % k] += dp[r];
            }
            dp = next;

            for(int r = 0 ; r<k ; r++){
                result[r] += dp[r];
            }
        }
        return result;
    }
};