��һ���ַ�������С��ʾ������һ���ַ���ͷ��β���������γ�һ��������һ��λ�öϿ�ʹ�����������С�ġ�


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
