class Solution {
public:
    int maxProduct(int n) {
        int temp = n;
        int max1 = -1 , max2 = -1;
        while(temp>0){
            int digit = temp%10;
            temp/=10;
            if(digit >= max1){
                max2 = max1;
                max1 = digit;
            }
            else if(digit < max1 && digit > max2){
                max2 = digit;
            }
        }
        return max1*max2;
    }
};