class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int i = 0;
       int maxm = 0;

       for(int j =0 ; j< nums.size() ; j++){
        if(nums[j] != 0){
            i++;
            maxm = max(i,maxm);
        }
        else i = 0;
        
       }
       return maxm;
    }
};