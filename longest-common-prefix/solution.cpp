class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str;
        int len = strs.size();
        int j =0;
        while(j<strs[0].size()){
         for(int i = 0 ; i<len-1 ; i++){
            if(j>=strs[i].size()) return str;
            if(strs[i][j] != strs[i+1][j]) return str;
        }
        str+=(strs[0][j]);
        j++;
    } 
    return str;
    }
};