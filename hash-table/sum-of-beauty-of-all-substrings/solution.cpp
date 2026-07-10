class Solution {
public:
    int beautySum(string s) {
        int len = s.size();
        int beauty_sum = 0;
        for(int i = 0; i<len ; i++){
            vector<int> count(26,0);
            for(int j = i ; j<len ; j++){
               count[s[j] - 'a']++;
               int maxi = INT_MIN;
               int mini = INT_MAX;

               for(int k = 0 ; k<26 ; k++){
                int freq = count[k];
                if(freq>0){
                    maxi = max(maxi,freq);
                    mini = min(mini,freq);
                }
               }
               beauty_sum+=(maxi-mini);
            }
        }
        return beauty_sum;
    }
};