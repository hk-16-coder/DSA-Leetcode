class Solution {
public:
    bool checkString(string s) {
        bool flag = true;
        for(char ch : s){
            if(ch == 'b'){
                flag = false;
            }

            if(ch == 'a' && flag == false){
                return false;
            }
        }

        return true;
    }
};