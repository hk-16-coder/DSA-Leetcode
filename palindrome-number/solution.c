
bool isPalindrome(int x) {
    int rev=0;
    int temp=x;

    while(temp>0){
        if(rev>INT_MAX/10 || rev== INT_MAX/10 ) return false;
        rev =rev*10 +temp%10;
        temp/=10;
    }
    if(rev==x)  return true;
         else return false;
}












