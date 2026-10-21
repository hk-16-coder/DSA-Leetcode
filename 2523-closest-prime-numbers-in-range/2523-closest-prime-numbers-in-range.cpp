class Solution {
public:
    vector<bool> sieve(int left , int right){
        vector<bool> isPrime(right -left + 1 , true);

        for(int i = 2 ; i*i <= right ; i++){
            int start = max(i * i, ((left + i - 1) / i) * i);

            for(int j = start ; j<=right ; j+=i){
                if(j - left >= 0)isPrime[j-left] = false;
                }
            
        }

        if(left == 0){
            isPrime[0] = false;
            if(right >= 1) isPrime[1] = false;
        } 
        else if (left == 1){
            isPrime[0] = false;
        }

        return isPrime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> arr = sieve(left , right);
        vector<int> ans = {-1,-1};

        int mini = 1e7;
        int prev = -1;
        for(int i = 0 ; i<arr.size() ; i++){
            if(arr[i]){
                if(prev != -1 && i-prev < mini){
                    mini= i - prev;
                    ans = {prev + left , i + left};

                    if(mini <= 2) return ans;
                }
                prev = i;
            }
        }

        return ans;
    }
};