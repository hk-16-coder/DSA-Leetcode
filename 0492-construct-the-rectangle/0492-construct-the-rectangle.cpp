class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2,0);
        int x = INT_MAX;

        for(int i = 1 ; i<=sqrt(area) ; i++){
            if(area%i == 0){
                if(x > area/i - i){
                    x = area/i - i;
                    ans[0] = area/i;
                    ans[1] = i;
                }
            }
        }
        return ans;
    }
};