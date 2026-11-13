class Solution {
public:
    long long countValidSubstrings(string s) {
        int i = 0 , j = 0;
        int n = s.size();

        long long cnt = 0;
        while(j<n){
            if(j>=2 && s[j] == 'c' && s[j-1] == 'b' && s[j-2] == 'a'){
                i = j - 1;
            }
            cnt += j - i + 1;
            j++;
        }
        return cnt;
    }
};