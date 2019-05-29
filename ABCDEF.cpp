#include<bits/stdc++.h>
using namespace std;
#define LL long long int
LL a[10005], b[1000005], c[1000005];
int main()
{
    LL i, n, j, k, ans=0, d=0, ind1, ind2, res1, res2;
    scanf("%lld",&n);
    for(j=0; j<n; j++)
    {
        scanf("%lld",&a[j]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            for(k=0; k<n; k++)
            {
                b[d]=a[i]*a[j]+a[k];
                d++;
            }
        }
    }
    ind1=d;
    d=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            for(k=0; k<n; k++)
            {
                if(a[i]==0) continue;
                c[d]=(a[i]*(a[j]+a[k]));
                d++;
            }
        }
    }
    ind2=d;
    sort(b,b+ind1);
    sort(c,c+ind2);
    for(i=0; i<ind1; i++)
    {
        res1=lower_bound(c,c+ind2,b[i])-c;
        res2=upper_bound(c,c+ind2,b[i])-c;
        ans=ans+(res2-res1);
    }
    printf("%lld\n",ans);
    return 0;
}
