class Solution {
public:
    int candy(vector<int>& ratings) {
        int total = 0;
        int n = ratings.size();
        if(n==1) return 1;
        vector<int> candies(n,1);
        for(int i = 1; i<n ; i++){
           // left to right
           if(ratings[i]>ratings[i-1]){
              candies[i] = candies[i-1] + 1;
            }
        }
        for(int i = n-2 ; i>=0 ; i--){
            // right to left
            if(ratings[i]>ratings[i+1]){
                candies[i] = max(candies[i],candies[i+1] + 1);
            }
        }
        for(int i = 0 ; i<candies.size(); i++){
            total+=candies[i];
        }
        return total;
    }
};