class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> freq;
        int max_len = 0;
        int left = 0;
        int right = 0;
        int max_freq = 0;
        int n = s.size();
        while(right<n){
            freq[s[right]]++;
            max_freq = max(max_freq,freq[s[right]]);

            // length of window is right - left + 1
            // length - max_freq should be less than k
            if((right - left + 1) - max_freq >k){
                freq[s[left]]--;
                if(freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
            max_len = max(max_len,right-left+1);
            right++;
        }

        return max_len;
    }
};