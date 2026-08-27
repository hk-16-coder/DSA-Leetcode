class Solution {
public:
    bool checkPerfectNumber(int num) {
        long long sum = 0;
        for(int i = 1 ; i<=num/2 ; i++){
            if(num%i == 0){
                sum+=i;
                if(sum>num) return false;
            }
        }
        if(num == sum) return true;
        return false;
    }
};