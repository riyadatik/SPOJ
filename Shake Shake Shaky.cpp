#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
long long int a[1000000];
long long int F(long long int mid, long long int n)
{
    long long int i, res=0;
    for(i=0; i<n; i++)
    {
        res=res+(a[i])/mid;
    }
    return res;
}
long long int binary_src(long long int lo, long long hi, long long int k, long long int n)
{
    long long int mid, ans=lo, res;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(mid!=0)
        {
            res=F(mid,n);
        }
        if(res>=k)
        {
            lo=mid+1;
            if(mid>ans)
            {
                ans=mid;
            }
        }
        else
        {
            hi=mid-1;
        }
    }
    return ans;
}
int main()
{
    long long int t, n, i, j, k, ans;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld%lld",&n,&k);
        for(j=0; j<n; j++)
        {
            scanf("%lld",&a[j]);
        }
        sort(a,a+n);
        ans=binary_src(a[n-1]/k,a[n-1],k,n);
        printf("%lld\n",ans);
    }
    return 0;
}
