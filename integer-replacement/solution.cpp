class Solution {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        long long temp = n;
        
        while(temp!=1){
            if(temp == 3) return cnt + 2;
            if(temp%2 == 0){
                temp = temp/2;
                cnt++;
            }
            else{
                if(((temp+1)/2)%2 == 0) temp = temp+1;
                else temp = temp - 1;
                cnt++;
            }
        }
        return cnt;
    }
};