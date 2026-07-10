class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        // largest - smallest or  maximum - minimum 
        long long ans = 0;
        vector<int> NGE(nums.size());
        vector<int> PGE(nums.size());
        vector<int> NSE(nums.size());
        vector<int> PSE(nums.size());
        stack<int> st; 
       
        for(int i = 0 ; i<nums.size() ; i++){
            while(!st.empty() && nums[st.top()]<=nums[i])st.pop();
            if(st.empty()) PGE[i] = -1;
            else PGE[i] = st.top();
            st.push(i);
        }
        st = stack<int>(); // clearing the stack
        for(int i = nums.size() - 1 ; i>=0 ; i--){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(st.empty()) NGE[i] = nums.size();
            else NGE[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = 0 ; i<nums.size() ; i++){
            while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
            if(st.empty()) PSE[i] = -1;
            else PSE[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = nums.size() - 1 ; i>=0 ; i--){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            if(st.empty()) NSE[i] = nums.size();
            else NSE[i] = st.top();
            st.push(i);
        }

        for(int i = 0 ; i<nums.size() ; i++){
            long long leftMin = i - PSE[i];
            long long rightMin = NSE[i] - i;
            long long leftMax = i - PGE[i];
            long long rightMax = NGE[i] - i;
            ans+= (1LL*nums[i])*((leftMax*rightMax) - (leftMin*rightMin));
        }
        return ans;
    }
};