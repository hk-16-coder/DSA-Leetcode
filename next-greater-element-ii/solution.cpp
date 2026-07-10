class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i<n;i++){
            nums.push_back(nums[i]);
        }
        
        vector<int> ans(2*n);
        stack<int> st;
        for(int i = nums.size() - 1 ; i>=0 ; i--){
            while(!st.empty() && st.top() <= nums[i]) st.pop();

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(nums[i]);
        }
       
        vector<int> half(ans.begin() , ans.begin() + n);
        return half;
    }
};