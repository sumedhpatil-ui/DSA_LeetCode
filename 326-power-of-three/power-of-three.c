bool isPowerOfThree(int n) {
while(n)
    {
        if(n%3==0)
            n = n/3;
        else
            break;
    }
    return n==1;
}