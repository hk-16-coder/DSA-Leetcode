class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt = 0;
        for(char ch : s){
            if(ch == '0') cnt0++;
            if(ch == '1') cnt1++;
            if(abs(cnt0 - cnt1) <= 1) cnt++;
        }
        return cnt;
    }
};