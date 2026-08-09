class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> count = {1 , 9 , 9*9 , 9*9*8 , 9*9*8*7 , 9*9*8*7*6 , 9*9*8*7*6*5 , 9*9*8*7*6*5*4 , 9*9*8*7*6*5*4*3};

        int ans = 0;
        for(int i = 0 ; i<=n ; i++){
            ans+=count[i];
        }
        return ans;
    }
};