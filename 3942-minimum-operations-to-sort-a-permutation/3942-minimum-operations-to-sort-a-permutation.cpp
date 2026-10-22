class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        for(int i = 0 ; i<n ; i++){
            if(nums[i] == 0){
                start = i;
                break;
            }
        }

        bool asc = true , desc = true;

        for(int i = 1 ; i<n ; i++){
            int val = nums[(start + i) % n];

            if(val != i) asc = false;
            if(val != n-i) desc = false;

            if(!asc && !desc) return -1;
        }

        if(asc){
            return min(start , n - start + 2);
        }
        return min(n - start , start + 2);
    }
};