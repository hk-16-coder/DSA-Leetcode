class Solution {
public:
    long long gcd (int a , int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long maxPairStrength(vector<int>& nums) {
        long long maxi = 0;
        for(int i = 0 ; i<nums.size();  i++){
            for(int j = 0 ; j<nums.size() ; j++){
                long long gcdVal = gcd(nums[i] , nums[j]);
                long long val = (1LL*nums[i] * nums[j]) / (gcdVal*gcdVal);
                maxi = max(maxi,val);
            }
        }
        return maxi;
    }
};