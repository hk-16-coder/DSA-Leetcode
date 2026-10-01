class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n-k+1;
        vector<int> leftBest(m);
        vector<int> rightBest(m);
        vector<int> window(m);
        
        long long sum = 0;
        for(int i = 0 ; i<k ; i++) sum+=nums[i];
        window[0] = sum;

        for(int i = 1 ; i<=n-k ; i++){
            sum = sum - nums[i-1] + nums[i+k-1];
            window[i] = sum;
        }

        for(int i = 1 ; i<m ; i++){
            if(window[i] > window[leftBest[i-1]]) leftBest[i] = i;
            else leftBest[i] = leftBest[i-1];
        }

        rightBest[m-1] = m-1;
        for(int i = m-2 ; i>=0 ; i--){
            if(window[i] >= window[rightBest[i+1]]) rightBest[i] = i;
            else rightBest[i] = rightBest[i+1];
        }

        vector<int> ans;
        long long best = 0;

        for(int i = k ; i <= n - 2*k ; i++){
            int left = leftBest[i-k];
            int right = rightBest[i+k];

            long long score = window[left] + window[i] + window[right];
            if(score > best){
                best = score;
                ans = {left , i , right};
            }
        }

        return ans;
    }
};