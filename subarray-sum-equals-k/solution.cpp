class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0 ; 
        map <int,int> PresumCount;
        PresumCount[0] = 1;
        int Presum = 0;

        for(int i = 0 ; i<nums.size() ; i++){
           Presum += nums[i];
           int rem = Presum - k;
           cnt += PresumCount[rem];
           PresumCount[Presum]++ ;
        }
        return cnt;
    }
};