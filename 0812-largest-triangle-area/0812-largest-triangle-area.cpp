class Solution {
public:
    double area(int x1 , int y1 , int x2 , int y2 , int x3 , int y3){
        double a = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        double b = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
        double c = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));

        double s = (a+b+c)/2.0;
        if(s<=a || s<=b || s<=c) return 0;
        
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;

        int n = points.size();
        
        for(int i = 0 ; i<n-2 ; i++){
                for(int j = i+1 ; j<n-1 ; j++){
                    for(int k = j+1 ; k<n ; k++){
                         double Area = area(points[i][0] , points[i][1] , points[j][0] , points[j][1] , points[k][0] ,
                          points[k][1]);

                        ans  = max(ans,Area);
                    }
                }
        }
    return ans;
    }
};