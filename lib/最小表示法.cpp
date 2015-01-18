求一个字符串的最小表示法，即一个字符串头和尾连接起来形成一个环，从一个位置断开使得这个串是最小的。


#include <iostream>

using namespace std;
int MinRepresentation(char * s,int l)
{
    int i=0,j=1,k=0;
    int t;
    while(i<l&&j<l&&k<l)
    {
        t = s[(i+k)%l] - s[(j+k)%l];
        if(t == 0)
        k++;
        else
        {
            if(t>0)
            i += k+1;
            else
            j += k+1;
            if(i == j)
            j++;
            k = 0;
        }
    }
    return min(i,j);
}
int main()
{
    int n,x;
    char a[100005];
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x >> a ;
        cout << MinRepresentation(a,x) << endl;
    }
    return 0;
}
