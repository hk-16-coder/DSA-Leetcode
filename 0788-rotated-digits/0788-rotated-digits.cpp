class Solution {
public:
    int rotatedDigits(int n) {
        // 3 4 7
        int total = n;

        for(int i = 1 ; i<=n ; i++){
            string s = to_string(i);
            string temp = "";
            for(char ch : s){
                if(ch == '3' || ch == '4' || ch == '7') {
                    total -= 1;
                    break;
                }
                else if(ch == '0' || ch == '1' || ch == '8') temp += ch;
                else if(ch == '2') temp += '5';
                else if(ch == '5') temp += '2';
                else if(ch == '6') temp += '9';
                else if(ch == '9') temp += '6';
            }
            if(temp == s) total -= 1;
        }
        return total;
    }
};