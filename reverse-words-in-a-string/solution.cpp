class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        reverse(s.begin(),s.end());
        string ans = "";
        
        for(int i = 0 ; i<len ; i++){
            string word = "";
            while(i<len && s[i] != ' '){
               word+=s[i];
               i++;
            }
            reverse(word.begin(),word.end());
            if(word.size()>0) ans += " " + word;
        }
        return ans.substr(1); // as 0th index would have space so we return string from 1st char
    }
};