class Solution {
public:
    int extra(char a , char b){
        int diff = abs((a-'a') - (b-'a'));

        return min(diff,26-diff);
    }
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;

        for(int i = 0 ;i<n ; i++){
            int cost = i;
            int l = 0 , r = n-1;
            while(l<r){
                char a = s[(l+i)%n];
                char b = s[(r+i)%n];

                cost+=extra(a,b);

                l++;
                r--;
            }
            ans = min(ans,cost);
        }
        return ans;
    }
};