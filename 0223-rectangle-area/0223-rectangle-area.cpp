class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long area1 = abs(1LL * (ax2-ax1)*(ay2-ay1));
        long long area2 = abs(1LL * (bx2-bx1)*(by2-by1));
        
        long long area = area1 + area2;
        long long overlap = 0;

        int left = max(ax1,bx1);
        int right = min(bx2,ax2);
        int top = min(by2,ay2);
        int bottom = max(ay1,by1);

        if(left<right && bottom<top){
            overlap = 1LL*(right-left)*(top-bottom);
        }
        return area  - overlap;
    }
};