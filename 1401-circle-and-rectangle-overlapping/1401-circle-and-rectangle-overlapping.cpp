class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // CALCULATE DISTANCE OF POINT ON RECT NEAREST TO CIRCLE WITH CENTER OF CIRCLE
        int x0 = max(x1 , min(x2 , xCenter));
        int y0 = max(y1 , min(y2 , yCenter));

        int dx = xCenter - x0;
        int dy = yCenter - y0;

        int dist = dx*dx +  dy*dy;
        if(dist <= radius*radius) return true;
        return false;
    }
};