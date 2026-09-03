class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = INT_MAX;
        int even  = INT_MAX;

        for(int i = 0 ; i<nums1.size() ; i++){
            if(nums1[i] %2 == 0){
                even = min(even,nums1[i]);
            }
            else odd = min(odd,nums1[i]);
        }

        if(odd == INT_MAX || even == INT_MAX) return true;
        if(even - odd >= 1) return true;
        return false;
    }
};