class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;
        for(int x : nums) st.insert(x);
         
        int i = 1;
        while(true){
          if(st.count(k*i) == 0) return k*i;
          i++;
        }
        return -1;
    }
};