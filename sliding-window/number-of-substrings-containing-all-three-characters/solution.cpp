class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3,0);
        int cnt = 0;
        int n = s.size();
        int left = 0;
        int right = 0;
        while(right<n){
            freq[s[right] - 'a']++;
           
            while(min(freq[0],min(freq[1],freq[2])) > 0){
                cnt++;
                int remaining = n - right - 1;
                cnt+=remaining;
                freq[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        
       return cnt;
    }
};