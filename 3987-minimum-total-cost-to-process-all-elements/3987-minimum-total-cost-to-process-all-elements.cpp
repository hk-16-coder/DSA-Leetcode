class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long balance = k;
        long long cost = 0;
        long long cnt = 1;
        long long modulo = 1e9 + 7;

        for(int i = 0 ; i<nums.size(); i++){
            if(balance >= nums[i]){
                balance-=nums[i];
            }
                
            else{
                long long diff = nums[i] - balance;
                long long x = diff/k;
                if(diff%k != 0) x = (diff/k) + 1;
                balance = balance + x*k;
                long long n = cnt + x - 1;
                
                __int128 add =  (__int128)n*(n+1)/2 - (__int128)cnt*(cnt-1)/2;
                cost = (cost + 1LL*add%modulo)%modulo;
                
                cnt = cnt + x;
                balance = balance - nums[i];
            }
        }
        return (int)cost%modulo;
    }
};