class Solution {
public:
    string RLE(string& s){
        string temp = "";
        int n = s.size();
        int i = 0 ;
        
        while(i<n){
            int cnt = 1;
            char ch = s[i];

            while(i+1 < n && s[i+1] == s[i]){
                cnt++;
                i++;
            }

            temp += to_string(cnt) + ch;
            i++;
        }
       
        return temp;
    }
    string countAndSay(int n) {
        string s = "1";
        while(n-- > 1){
            s = RLE(s);
        }

        return s;
    }
};