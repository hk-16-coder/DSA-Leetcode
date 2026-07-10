class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int total = 0;
        int n = cost.size();
        for(int i = 1; i<=n ; i++){
            if(i%3 == 0)continue;
            else total += cost[n-i];
        }
        return total;
    }
};