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
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> prime = sieve(n);
        vector<vector<int>> ans;
        int i = 0 , j = prime.size() - 1;

        while(i<=j){
            if(!prime[i]) i++;
            else if(!prime[j]) j--;
            else{
               if(i + j == n){
                    ans.push_back({i,j});
                    i++;
               } 

               else if(i + j <  n) i++;
               else j--;
            }
        }
        return ans;
    }
};