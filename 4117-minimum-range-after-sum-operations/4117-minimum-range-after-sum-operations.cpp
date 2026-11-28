class Solution {
public:
    int minRange(int a, int b, int c) {
        vector<int> arr = {a , b , c};
        sort(arr.begin() , arr.end());

        int range = arr[2] - arr[0];
        return min(range , arr[1]);

    }
};