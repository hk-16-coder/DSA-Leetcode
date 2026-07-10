class Solution {
public:
    long long modulo = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        vector<int> NSE(arr.size());
        vector<int> PSE(arr.size());
        stack<int> st1;
        stack<int> st2;
        for(int i = 0 ; i<arr.size();i++){
            while(!st1.empty() && arr[st1.top()]>=arr[i]) st1.pop();
            if(st1.empty()) PSE[i] = -1;
            else PSE[i] = st1.top();
            st1.push(i);
        }

        for(int i = arr.size() - 1 ; i>=0 ; i--){
            while(!st2.empty() && arr[st2.top()] > arr[i]) st2.pop();
            if(st2.empty()) NSE[i] = arr.size();
            else NSE[i] = st2.top();
            st2.push(i);
        }
        for(int i = 0 ; i<arr.size() ; i++){
            long long left = i - PSE[i];
            long long right = NSE[i] - i;
            ans+= ((1LL*arr[i])*left*right) % modulo;
            ans = ans%modulo;
        }
        return (int)ans;
        
    }
};