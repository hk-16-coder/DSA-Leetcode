class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int i = 0 , j = 0;
        int cnt = 0;
        while(j<s.size()){
           if(s[j] == '1') cnt++;

           while(cnt>k){
            if(s[i] == '1') cnt--;
            i++;    
           }

           if(cnt == k){

            while(i<=j && s[i] == '0'){
                i++;
            }

            string temp = s.substr(i,j-i+1);
            if(ans == "") ans = temp;

            else if(temp.size() < ans.size()) ans = temp;
            else if(temp.size() == ans.size() && temp < ans) ans = temp;
           }
           j++;
        }

        return ans;
    }
};