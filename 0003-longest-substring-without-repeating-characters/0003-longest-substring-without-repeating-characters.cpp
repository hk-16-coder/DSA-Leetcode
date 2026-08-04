class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int left = 0;
        int right = 0;
        int max_len = 0;
        while(right<s.size()){
               if(freq[s[right]] == 0){
                freq[s[right]]++;
                right++;
               }
               else{
                freq[s[left]]--;
                left++;
               }
               max_len = max(max_len,right-left); 
        }
        return max_len;
    }
};