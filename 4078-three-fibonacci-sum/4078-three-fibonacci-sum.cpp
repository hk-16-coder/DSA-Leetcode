class Solution {
public:
    bool f(int prev , int cur , int& x){
        if(cur == x) return true;
        if(cur > x) return false;

        return f(cur , cur + prev , x); 
    }
    bool threeFibonacciSum(int n) {
        if(n%2 == 1) return false;
        int x = n/2;
        // x should be a fibonacci number
 
        return f(1 , 1 , x);       
    }
};