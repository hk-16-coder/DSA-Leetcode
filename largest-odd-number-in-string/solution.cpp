class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int len = num.size();
        int idx = -1;
        for(int i = len-1 ; i>=0;i--){
            if((int)num[i] %2 != 0) {
                idx = i;
                break;
            }
        }
       if(idx>=0){
        for(int i = 0 ; i<=idx;i++) ans+=(num[i]);
       } 
       return ans;
    }
};