bool isPowerOfTwo(int n) {
while(n)
    {
        if(n%2==0)
        {n/=2;}
        else
        break;
    }
    return n==1;
}