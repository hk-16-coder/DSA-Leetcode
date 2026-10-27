class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s = "";
        for(int i = 0 ; i<n ; i++){
            s += '.';
        }
        ans.push_back(s);

        for(int i = 1 ; i<m ; i++){
            string s2 = "";
            for(int j = 0 ; j<n ; j++){
                if(j == n-1) s2 += '.';
                else s2 += '#';
            }
            ans.push_back(s2);
        }

        return ans;
    }
};