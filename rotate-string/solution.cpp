class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false ;
        int j = 0;
        int n = s.length();
        while(j<n) {
            char ch = s[0];
         for(int i = 0 ; i<n ; i++){
           if(i<n-1) s[i]  = s[i+1];
           if(i==n-1) s[i] = ch;
        }
        j++;
        if(s == goal) return true; 
       }
       return false;
    }
};