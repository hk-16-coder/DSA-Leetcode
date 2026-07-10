class Solution {
public:
    long long modulo = 1e9 + 7;
    long long power(long long base , long long exp){
        if(exp == 0) return 1;
        long long half = power(base,exp/2);

        long long result = (half*half) % modulo;
        if (exp % 2 == 1) {
            result = (result * base) % modulo;
        }

        return result;
    }
    int countGoodNumbers(long long n) {
        if(n == 1) return 5;
        long long odd = n/2;
        long long even = n - odd;

        long long ans = (power(5,even)*power(4, odd)) % modulo;
        return (int)ans;
    }
};