class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0 , high = citations[n-1];

        int ans = 0;
        while(low<=high){
           int mid = low + (high - low)/2;
           int cnt = 0 ; 
           for(int i = 0 ; i<n ; i++){
            if(citations[i] >= mid) cnt++;
           }

           if(cnt>=mid){
            ans = mid;
            low = mid+1;
           }
           else high = mid-1;
        }
        return ans;
    }
};