class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> digits;
        long long temp = 1LL*n;
        long long sum = 0;
        while(temp>0){
            int digit = temp%10;
            sum+=digit;
            if(digit!=0) digits.push_back(digit);
            temp/=10;
        }
        reverse(digits.begin(),digits.end());
        long long num = 0;
        for(int i = 0 ; i<digits.size() ; i++){
              num = num*10 + digits[i];
        }
        return num*sum;
    }
};