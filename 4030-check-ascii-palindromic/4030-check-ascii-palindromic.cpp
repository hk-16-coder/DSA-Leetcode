class Solution {
public:
    string binary(int num){
        string ans = "";
        for(int i = 7 ; i>=0 ; i--){
            ans += ((num>>i) & 1) + '0';
        }
        return ans;
    }

    bool isPalindromic(string s) {
        string num = "";
        for(int i = 0 ; i<s.size()  ; i++){
            int val = s[i];
            num += binary(val);
        }

        int i = 0 , j = num.size()-1;
        while(i<j){
            if(num[i++] != num[j--]) return false;
        }

        return true;
    }
};