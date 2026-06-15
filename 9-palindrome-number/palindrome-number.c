bool isPalindrome(int x) {
    long long rev = 0;
    int num = x;
    while(x > 0)
    {
        rev = rev*10 + x % 10;
        x = x / 10;
    }
    if(num < 0) return false;
    else return rev == num;
}