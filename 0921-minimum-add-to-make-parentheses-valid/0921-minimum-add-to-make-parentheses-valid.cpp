class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int score = 0;

        for(char ch : s){
            if(ch == '(') score++;
            else score--;

            if(score < 0){
                ans += 1;
                score = 0;
            }
        }
        ans += score;
        return ans;
    }
};