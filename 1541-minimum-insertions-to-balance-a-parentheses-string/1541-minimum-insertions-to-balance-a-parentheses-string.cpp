class Solution {
public:
    int minInsertions(string s) {
        int score = 0;
        int ins = 0;
        for(char ch : s){
            if(ch == '('){
                score += 2;
                if(score % 2 == 1){
                    score--;
                    ins++;
                }
            }

            else{
                score--;
                if(score < 0){
                    ins += 1;
                    score += 2;
            
                }
            }
        }
        
       return ins + score;
    }
};