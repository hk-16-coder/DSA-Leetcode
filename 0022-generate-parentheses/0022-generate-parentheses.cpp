class Solution {
public:
    vector<string> ans;
    void addS (string &temp , int left , int balance , int n){
        if(temp.size() == 2*n) {
            ans.push_back(temp);
            return;
            }

        // pick
        if(left<n){
            temp.push_back('(');
            addS(temp,left+1,balance+1,n);
            temp.pop_back();
        }
        int right = temp.size() - left;

        // not pick
        if(balance>0 && right<left){
            temp.push_back(')');
            addS(temp,left,balance-1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        addS(temp,0,0,n);
        return ans;
    }
};