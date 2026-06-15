bool isPowerOfFour(int n) {
    if(n < 4 && n == 1)
        return true;
    else if(n < 4 && n%4 != 1)
        return false;
    else if(n % 4 == 0)
        return isPowerOfFour(n/4);
    return false;
}