class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        long long ans = 0;

        for(int x : nums){
            while(!arr.empty() && arr.back() > x) arr.pop_back();
            ans += lower_bound(arr.begin() , arr.end() , x) - arr.begin();
            arr.push_back(x);
        }
        return ans;
    }
};