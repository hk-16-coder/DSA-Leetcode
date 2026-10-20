class Solution {
public:
    vector<bool> sieve(int n){
        vector<bool> isPrime(n+1 , true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2 ; i*i <= n ; i++){
            if(isPrime[i]){
                for(int j = i*i ; j<=n ; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    vector<int> maxPrimes(int n, int s) {
        vector<bool> prime = sieve(n);
        vector<int> ans;
        long long sum = 0;

        for(int i = 0 ; i<prime.size() ; i++){
            if(prime[i]){
                if(sum + i <= s){
                    ans.push_back(i);
                    sum += i;
                }
                else break;
            }
        }

        return ans;
    }
};