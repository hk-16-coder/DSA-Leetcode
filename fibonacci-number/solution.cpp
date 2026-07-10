class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        int a = 0;
        int b = 1;
        for(int i = 1 ; i<n ; i++){
            int temp = a;
            a = b;
            b = temp+b;
        }
        return b;
    }
};