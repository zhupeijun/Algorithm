// m^n % k
int quickpow(int m,int n,int k)
{
    int b = 1;
    while (n > 0)
    {
          if (n & 1)
             b = (b*m)%k;
          n = n >> 1 ;
          m = (m*m)%k;
    }
    return b;
} 