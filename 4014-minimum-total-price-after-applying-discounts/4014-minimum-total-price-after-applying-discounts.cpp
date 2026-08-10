class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans = 0;
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());

        int i = prices.size() - 1 , j = discounts.size() - 1;
        while(i>=0 && j>=0){
            double p = prices[i];
            double d = discounts[j];
            ans  = ans + (double)((p*(100-d))/100.0);
            i--;
            j--;
        }
        while(i>=0) ans += (double)prices[i--];
        return ans;

    }
};