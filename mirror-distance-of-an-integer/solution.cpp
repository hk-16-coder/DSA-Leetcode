class Solution {
public:
    int mirrorDistance(int n) {
        long long rev = 0;
        int temp = n;
       while (temp>0){
        int last_digit = temp%10;
        temp/=10;
        rev = rev*10 + last_digit;
       }
       return abs(rev-n);
    }
};