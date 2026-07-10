class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area  = 0;
        int n = heights.size();
        vector<int> NSE(n);
        vector<int> PSE(n);
        stack<int> st;
        for(int i = 0 ; i<n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) PSE[i] = -1;
            else PSE[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = n - 1 ; i>=0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) NSE[i] = n;
            else NSE[i] = st.top();
            st.push(i);
        }
        for(int i = 0 ; i<n ; i++){
            max_area = max(max_area,heights[i]);
            int right = NSE[i];
            int left = PSE[i];
           
            int width = right-left-1;
            int area = width*heights[i];
            max_area = max(max_area,area);
        }
        return max_area;
    }
};