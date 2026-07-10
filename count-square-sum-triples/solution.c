#include<stdio.h>


int countTriples(int n) {
    int count = 0;
   if(n>=1 && n<=250) {
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            for(int k = 1; k<=n ; k++){
                if(i*i +j*j == k*k) count++ ;
            }
        }
    }
   }
    return count;
   
}
/*int main(){
    int n;
    scanf("%d",&n);
    printf("%d",countTriples(n));
    return 0;

}*/