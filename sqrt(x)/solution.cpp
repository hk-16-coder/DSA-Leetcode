class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
      int low = 0;
      int high = x-1;
      while(low<=high){
        long long mid = low + (high-low)/2;
        long long temp = mid * mid;
        if(temp == x) return (int)mid;
        if(temp > x) high = mid-1;
        else low = mid+1;
      }
      return low-1;
    }
};