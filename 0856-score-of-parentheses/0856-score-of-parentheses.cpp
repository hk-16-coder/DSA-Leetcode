class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int nested = 0;

        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '('){
                nested++;
            }

            else{
                nested--;
                if(s[i-1] == '('){
                    score += pow(2,nested);
                }
            }
        }
        return score;
    }
};