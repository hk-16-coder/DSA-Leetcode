class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        vector<int> max_on_left(n);
        vector<int> max_on_right(n);
       
        max_on_left[0] = height[0];
        for(int i = 1 ; i<n ; i++){
               max_on_left[i] = max(height[i],max_on_left[i-1]);
        }
        max_on_right[n-1] = height[n-1];
        for(int i = n-2 ; i>=0 ; i--){
            max_on_right[i] = max(height[i],max_on_right[i+1]);
        }
        int ans = 0;
        for(int i = 1 ; i<n-1  ; i++){
            ans+=min(max_on_left[i] , max_on_right[i]) - height[i];
        }
        return ans;
    }
};