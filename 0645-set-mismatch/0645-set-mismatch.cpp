class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        int sum = n*(n+1)/2;
        int sum_left = 0;
        int sum0 = 0;
        for(int x : nums){
          sum0+=x;
             if(st.count(x) == 0) sum_left+=x;
             st.insert(x);
        }
        int rem = sum - sum_left;
        int rep = sum0 - sum + rem;

        return {rep,rem};

    }
};