class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        int idx = 0;
        while(idx<len && s[idx] == ' ') idx++;

        int sign = 1;
        if(idx<len){
            if(s[idx] == '+' || s[idx] == '-'){
                if(s[idx] == '-') sign = -1;
                idx++;
            }
        }
        long long ans = 0;
        while(idx<len && isdigit(s[idx])){
            int digit = s[idx] - '0';
            ans = ans*10 + digit;

            if(sign*ans >= INT_MAX) return INT_MAX;
            else if (sign*ans <= INT_MIN) return INT_MIN;

            idx++;
        }
        return sign*ans;
    }
};