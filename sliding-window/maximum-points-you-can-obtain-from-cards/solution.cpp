class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total_sum = 0;
        int min_sum = 0;
        for(int i = 0 ; i<n ; i++){
            total_sum+=cardPoints[i];
            if(i<n-k) min_sum+=cardPoints[i];
        }
        if(n==k) return total_sum;
        // find a subarray of length n-k whose sum is minimum
        int left = 0;
        int right = n-k;
        int sum = min_sum;
        while(right<n){
             sum = sum + cardPoints[right] - cardPoints[left];
             min_sum = min(min_sum,sum);
             left++;
             right++;   
        }
       return total_sum - min_sum;
    }
};