class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num * 9 < sum) return "";
        string s = "";

        while(num--){
            for(int i = 9 ; i>=0 ; i--){
                if(sum >= i){
                    sum -= i;
                    char ch = i + '0';
                    s += ch;
                    break;
                }
            }
        }
        return s;
    }
};