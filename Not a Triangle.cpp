#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
int a[20005];
int binary_src(int lo, int hi, int target)
{
    long long mid, index=0;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(a[mid]>target)
        {
            index=mid;
            hi=mid-1;
        }
        else if(a[mid]<=target)
        {
            lo=mid+1;
        }
    }
    return index;
}
int main()
{
    int n, i, j, k, res, ans, res1;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
        {
            break;
        }
        mem(a,0);
        ans=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        for(j=1; j<n-1; j++)
        {
            for(k=j+1; k<n; k++)
            {
                res=a[j]+a[k];
                res1=binary_src(k+1,n,res);
                if(res1!=0)
                {
                    ans=ans+(n-res1+1);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
