class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int k = 0;
        if(n % 2 == 0) k = n/2;
        else k = n/2 + 1;

        priority_queue<long long , vector<long long> , greater<long long>> pq;
        for(int x : nums){
            pq.push(x*x);
            if(pq.size() > k){
                int val = pq.top();
                pq.pop();
                sum -= val;
            }
        }

        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            sum += val;
        }

        return sum; 
    }
};