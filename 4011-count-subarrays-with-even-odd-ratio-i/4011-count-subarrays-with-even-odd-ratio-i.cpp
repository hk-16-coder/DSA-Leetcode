class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int cnt = 0;
       // int even = 0 , odd = 0;
        for(int i = 0 ; i<nums.size(); i++){
            int even = 0 , odd = 0;
            if(nums[i]%2  == 0)even++;
            else odd++;
            for(int j = i ; j<nums.size() ; j++){
               if(j!=i){   
                 if(nums[j]%2 == 0) even++;
                 else odd++;
               }
                if(odd>0 && even*b <= a*odd) cnt++;
            }
        }
        return cnt;
    }
};