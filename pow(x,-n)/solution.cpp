class Solution {
public:
    double myPow(double x, int n) {
        if(x==1 && n!=0) return 1;
        else if(x==-1 && n%2 == 0) return 1;
        else if (x==-1 && n%2 ==1) return -1;
        else if (n==0) return 1;
        else if ((n/x > 1e8) || (x>1 && n<-1e8)) return 0;

        long double product = 1;
        long long N = n;
        N = abs(N);
        for(int i = 0 ; i<N ; i++){
            product*=x;
        }
        if(n<0) return 1/product;
        else return product;
    }
};