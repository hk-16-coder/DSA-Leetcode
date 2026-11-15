class Solution {
public:
    const int MOD = 1e9 + 7; 
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0;
        long long cnt = 0;

        int odd = 0 , even = 1; // sum = 0 is even

        for(int num : arr){
            sum += num;

            if(sum % 2 == 0){
                cnt += odd;
                even++;
            }

            else{
                cnt += even;
                odd++;
            }

            cnt = cnt % MOD;
        }

        return cnt;
    }
};