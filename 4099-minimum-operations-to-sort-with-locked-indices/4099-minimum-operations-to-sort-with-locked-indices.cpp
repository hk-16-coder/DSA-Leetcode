class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n-1 ; j++){
                if(nums[j] < nums[j+1]) continue;
                
                else{
                    if(locked[j]){
                        if(k == 0) return -1;
                        locked[j] = 0;
                        k--; cnt++;
                    }
                    if(locked[j+1]){
                        if(k == 0) return -1;
                        locked[j+1] = 0;
                        k--; cnt++; 
                    }

                    swap(nums[j] , nums[j+1]);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};