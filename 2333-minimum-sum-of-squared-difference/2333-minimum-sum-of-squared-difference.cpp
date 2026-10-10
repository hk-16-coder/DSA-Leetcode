class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL* (k1+k2);
        vector<int> freq(1e5 + 1);

        for(int i = 0 ; i<n ; i++){
            freq[abs(nums1[i] - nums2[i])]++;
        }

        for(int d = 1e5 ; d>0 && k>0 ; d--){
            if(freq[d] == 0) continue;

            int take = min(freq[d] , (int)k);

            freq[d] -= take;
            freq[d-1] += take;
            k -= take;
        }

        long long sum = 0;
        for(int d = 0 ; d<=1e5 ; d++){
            sum += 1LL* freq[d] * d * d;
        }

        return sum;
    }
};