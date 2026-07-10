class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        unordered_map<char,char> mpp;
        unordered_map<char,char> rev;
           
           // we check both mappings s->t and t->s and if they are not same we return false
        for(int i = 0 ; i<len ; i++){
            if(mpp.count(s[i])){
                if(mpp[s[i]] != t[i]) return false;
            } 
            else mpp[s[i]] = t[i];

            if(rev.count(t[i])){
                if(rev[t[i]] != s[i]) return false;
            }
            else rev[t[i]] = s[i];
        }
            
     return true;
    }
};