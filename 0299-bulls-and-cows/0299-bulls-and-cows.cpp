class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0 , y = 0;
        int n = secret.length();

        unordered_map<int,int> mpp;
        for(char ch : secret){
            int val = ch - '0';
            mpp[val]++;
        }

        for(int i = 0 ; i<n ; i++){
            int val = guess[i] - '0';

            if(guess[i] == secret[i]){
                x++;
                mpp[val]--;
            }
        }

        for(int i = 0 ; i<n ; i++){
            int val = guess[i] - '0';
            if(guess[i] != secret[i] && mpp[val] > 0){
                y++;
                mpp[val]--;
            }
        }    
        string ans = to_string(x) + "A" + to_string(y) + "B";
        return ans;
    }
};