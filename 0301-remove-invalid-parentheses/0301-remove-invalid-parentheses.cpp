class Solution {
public:
    void f(int i , int score , int left , int right , string& temp , string& s ,   unordered_set<string>& ans){
        if(i == s.size()){
            if(score == 0 && left == 0 && right == 0){
                ans.insert(temp);   
            }
            return;
        }

        char c = s[i];

        if(c == '('){
            if(left > 0){
                f(i+1 , score , left - 1 , right , temp , s , ans);
            }
            temp += c;
            f(i+1 , score + 1 , left , right , temp , s , ans);
            temp.pop_back();
        }

        else if(c == ')'){
            if(right > 0){
                f(i+1 , score , left , right - 1 , temp , s , ans);
            }

            if(score>0){
                temp += c;
                f(i+1 , score-1 , left , right , temp , s , ans);
                temp.pop_back();
            }
        }

        else{
            temp += c;
            f(i+1 , score, left, right , temp , s , ans);
            temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int left = 0 , right = 0;

        for(char c : s){
            if(c == '('){
                left++;
            }

            else if( c == ')'){
                if(left > 0) left--;
                else right++;
            }
        }

        string temp = "";
        unordered_set<string> ans;
        f(0 , 0 , left  , right , temp , s , ans);

        return vector<string>(ans.begin() , ans.end());
    }
};