class Solution {
public:
    string smallestPalindrome(string s) {
        int size = s.size();
        vector<int> hash(26,0);
        for(int i = 0 ; i<size/2 ; i++){
            hash[s[i] - 'a']++;
        }

        int i = 0 , j = 0;
        while(j<size/2){
            if(hash[i] == 0) i++;
            else{
                s[j] = char(i + 'a');
                s[size-j-1] =  s[j];
                hash[i]--;
                j++;
            }
        }
        return s;
    }
};