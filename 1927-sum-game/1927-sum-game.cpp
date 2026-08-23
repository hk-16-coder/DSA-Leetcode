class Solution {
public:
    bool sumGame(string num) {
        int cnt1 = 0 , cnt2 = 0;
        int sum1 = 0 , sum2 = 0;
        int n = num.size();

        for(int i = 0 ; i<n ; i++){
            if(i<n/2){
                if(num[i] == '?') cnt1++;
                else sum1+=(num[i] - '0');
            }
            else{
                if(num[i] == '?') cnt2++;
                else sum2+=(num[i] - '0');
            }
        }
        if(cnt1 == 0 && cnt2 == 0) return sum1 != sum2;

        // ODD '?'
        if((cnt1+cnt2) %2 == 1) return true;

        // EVEN
        // BOB CAN ONLY WIN IF LEFTSUM - RIGHTSUM == ((QRIGHT - QLEFT)/2)*9
        return (sum1 - sum2)*2 != 9*(cnt2-cnt1);
    }
};