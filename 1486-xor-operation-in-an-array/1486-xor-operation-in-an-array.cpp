class Solution {
public:
    int xorr(int n){
        if(n<0) return 0;
        if(n%4 == 0) return n;
        if(n%4 == 1) return 1;
        if(n%4 == 2) return n+1;

        return 0;
    }
    int xorOperation(int n, int start) {
        int end = start + 2*(n-1);

        int xorr1 = xorr(end/2);
        int xorr2 = xorr(start/2 - 1);

        int ans =  (xorr1^xorr2)*2;
        if(start%2 && n%2){
            ans^=1;
        }

        return ans;
    }
};