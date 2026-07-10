class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0 ; i<s.size();i++){
            sum1+=s[i];
            sum2+=t[i];
        }
        sum2+=t[s.size()];
        return (char)(sum2-sum1);
        
    }
};