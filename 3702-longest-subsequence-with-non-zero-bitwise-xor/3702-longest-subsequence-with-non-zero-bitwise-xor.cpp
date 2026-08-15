class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int XOR = 0;
        int n = nums.size();
        int zeros = 0;

        for(int x : nums){
           XOR^=x;
           if(x==0) zeros++;
        }
        if(XOR!=0) return n;
        if(zeros == n) return 0; // ALL ARE 0
        return n-1;
    }
};