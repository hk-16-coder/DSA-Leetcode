class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi = 0;

        for(int i = 0 ; i<points.size() - 1 ; i++){
            unordered_map<double,int> mpp;
            int cnt = 0; // counts vertical lines
            for(int j = i+1 ; j<points.size() ; j++){
                if(points[j][0] != points[i][0] ){
                    double slope = (double)(points[j][1] - points[i][1])/(points[j][0] - points[i][0]);
                    mpp[slope]++;
                }
                else cnt++;
            }
            if(mpp.empty()) maxi = max(maxi,cnt);
            for(auto it : mpp){
                maxi = max(maxi,max(cnt,it.second));
            }
        }
        
        return maxi + 1;
    }
};