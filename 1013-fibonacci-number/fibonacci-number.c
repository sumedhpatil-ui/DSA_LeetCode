int fib_tr(int n, int f_term, int s_term)
{
    if(n == 0)
        return f_term;
    else if(n == 1)
        return s_term;
    else
        return fib_tr(n-1, s_term, f_term + s_term);
}
int fib(int n){
    return fib_tr(n, 0, 1);
}