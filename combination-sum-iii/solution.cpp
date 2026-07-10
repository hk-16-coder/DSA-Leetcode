class Solution {
public:
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> ans;

    void combinations(int idx , int cnt , int sum , vector<int>& temp , int k ,int n){
        if(sum == n && cnt == k){
            ans.push_back(temp);
            return;
        }
        if(sum > n || cnt>k || idx>8) return;
        
        temp.push_back(nums[idx]);
        sum+=nums[idx];
        combinations(idx+1 , cnt+1 , sum , temp , k , n);

        temp.pop_back();
        sum-=nums[idx];
        combinations(idx+1 , cnt , sum , temp , k , n);
    } 
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>n) return {};
        vector<int> temp;
        combinations(0,0,0,temp,k,n);
        return ans;
    }
};