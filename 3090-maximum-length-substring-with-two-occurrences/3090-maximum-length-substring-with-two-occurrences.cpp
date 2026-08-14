class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int> mpp;
        int i = 0 , j = 0;
        int max_len = 0;
        while(j<s.size()){
            if(mpp[s[j] - 'a'] < 2){
                mpp[s[j] - 'a']++;
                j++;
                max_len = max(max_len,j-i);
            }
            else{
                mpp[s[i] - 'a']--;
                i++;
            }
        }
        return max_len;
    }
};