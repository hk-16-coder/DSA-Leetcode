class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len<=1) return s;
        string ans = "";
       
        for(int i = 1 ; i<len ; i++){
            // checking odd palindromes
            int low = i;
            int high = i;
            while(s[low] == s[high]){
                low--;
                high++;
                if(low == -1 || high == len) break;
            }
            
            string palindrome = s.substr(low+1,high-low-1);

            if(palindrome.size()>ans.size()) ans = palindrome;

            // checking even palindromes
            low = i-1;
            high = i;
            while(s[low] == s[high]){
                low--;
                high++;
                if(low == -1 || high == len) break;
            }
            palindrome = s.substr(low+1,high-low-1);

            if(palindrome.size()>ans.size()) ans = palindrome;
        }
     return ans;
    }
};