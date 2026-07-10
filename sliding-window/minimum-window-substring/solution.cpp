class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.size();
        unordered_map<char,int> freq;
        for(int i = 0 ; i<t.size() ; i++) freq[t[i]]++;

        int left = 0;
        int right = 0;
        int start = -1;
        int cnt = 0;
        int min_len = INT_MAX;
        while(right<s.size()){
            if(freq[s[right]] > 0) cnt++;
            freq[s[right]]--;

            while(cnt == n){
                if(right-left+1 < min_len){
                    min_len = right - left + 1;
                    start = left;
                }
                freq[s[left]]++;
                if(freq[s[left]] > 0) cnt--;
                left++;
            }
            right++;
        }
        if(start == -1) return "";
        return s.substr(start,min_len);
    }
};