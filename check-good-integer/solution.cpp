class Solution {
public:
    bool checkGoodInteger(int n) {
        long long digitSum = 0;
        long long squareSum = 0;
        int temp = n;
        while(temp>0){
            int digit = temp%10;
            temp/=10;
            digitSum+=digit;
            squareSum+=digit*digit;
        }
        if(squareSum - digitSum >= 50) return true;
        return false;
    }
};