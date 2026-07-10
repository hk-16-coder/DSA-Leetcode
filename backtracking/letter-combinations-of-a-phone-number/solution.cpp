class Solution {
public:
    vector<string> ans;
    void combinations(int idx , string& temp , string& digits , map<char , string>& mpp){
       if(idx >= digits.size()){
        ans.push_back(temp);
        return;
       }
       string curr = mpp[digits[idx]];
       for(int i = 0 ; i<curr.size() ; i++){
        temp.push_back(curr[i]);
        combinations(idx+1,temp,digits,mpp);
        temp.pop_back();
       }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        map<char,string> mpp = { {'2' , "abc"} , {'3' , "def"} , {'4' , "ghi"} , {'5' , "jkl"} , {'6' , "mno"} ,{'7' , "pqrs"} , {'8' , "tuv"} , {'9' , "wxyz"}};
        
        string temp = "";
        combinations(0,temp,digits,mpp);
        return ans;
    }
};