class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int diff = 0;
        for(int i = 0 ; i<n ; i++){
           diff = diff + gas[i]  - cost[i];
        }
        if(diff<0) return -1; // this means that cost of travelling is more than the available gas
        int currentGas = 0;
        int idx = 0;
        for(int i = 0 ; i<n ; i++){
            currentGas = currentGas + gas[i] - cost[i];
            if(currentGas<0){
                idx = i+1;
                currentGas = 0;
            }
        }
        return idx;    
    }
};