class Solution {
public: 
    void f(int idx , int dots , int start , string& s , string& temp , vector<string>& ans){
        int n = s.size();
        int remaining = n - idx;
        if(remaining < dots+1 || remaining > 3*(dots+1)) return;
        if(dots == 0){
            if(idx == n) return;
            if(n - idx > 3) return;
            
            string x = s.substr(idx);
            if(x.size() > 1 && x[0] == '0') return;

            if(stoi(x) > 255) return;

            temp += x;
            ans.push_back(temp);
            temp.resize(temp.size() - x.size());
            return;  
        }

        if(idx == n) return;
   
        string x = s.substr(start , idx - start + 1);
        if(x.size() > 1 && x[0] == '0') return;

        if(stoi(x) > 255) return;


        temp += x + '.';
        f(idx+1 , dots - 1 , idx + 1 , s , temp , ans);

        temp.resize(temp.size() - x.size() - 1);
        f(idx+1 , dots , start ,  s , temp , ans);
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp = "";
       
        f(0 , 3 , 0 , s , temp , ans);
        return ans;
    }
};