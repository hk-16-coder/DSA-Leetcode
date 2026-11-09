class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;

        int i = 0;
        int start = 0; //, end = 0;
        int n = s1.size();

        while(i<n){
            if(s1[i] != s2[i]) i++;
            else{
                if(start == i){
                    i++;
                    start = i;
                    //end = i;
                    continue;
                }
                else{
                    vector<string> s;
                    s.push_back(s1.substr(start , i - start));
                    s.push_back(s2.substr(start, i - start));
                    start = i+1;
                    i++;
                    ans.push_back(s);
                }
            }
        }

        if(start != i){
            vector<string> s;
            s.push_back(s1.substr(start , i - start));
            s.push_back(s2.substr(start, i - start));
            ans.push_back(s);
        }

        return ans;
    }
};