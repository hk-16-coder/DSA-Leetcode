class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        long long sum = 0;
        int i = nums.size() - 1;
        int cnt = 0;
        long long MUL = mul;
        while(MUL>0 && i>=0 && cnt!=k){
            if(cnt!=k){
                sum+=1LL*MUL*nums[i];
                cnt++;
            }
            i--;
            MUL--;
        }
        while(MUL<=0 && i>=0 && cnt!=k ){
            sum+=1LL*nums[i];
            i--;
            cnt++;
        }
        return sum;
    }
};