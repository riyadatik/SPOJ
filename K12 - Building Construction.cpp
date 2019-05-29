#include<bits/stdc++.h>
using namespace std;
#define LL long long int
LL a[10005], c[10005], n;
LL F(LL x)
{
    LL res=0, i;
    for(i=0; i<n; i++)
    {
        res=res+(abs(a[i]-x)*c[i]);
    }
    return res;
}
LL ternary_src(LL lo, LL hi)
{
    LL mid1, mid2, res1, res2, ans=100000000000000, c=200;
    while(c--)
    {
        mid1=lo+(hi-lo)/3;
        mid2=hi-(hi-lo)/3;
        res1=F(mid1);
        res2=F(mid2);
        if(res1>=res2)
        {
            lo=mid1;
        }
        else
        {
            hi=mid2;
        }
        ans=min(ans,res1);
        ans=min(ans,res2);
    }
    return ans;
}
int main()
{
    LL i, t, j, k, ans, mx, mn;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        mx=0;
        mn=100000;
        for(j=0; j<n; j++)
        {
            scanf("%lld",&a[j]);
            mx=max(mx,a[j]);
            mn=min(mn,a[j]);
        }
        for(j=0; j<n; j++)
        {
            scanf("%lld",&c[j]);
        }
        ans=ternary_src(mn,mx);
        printf("%lld\n",ans);
    }
    return 0;
}
