#include<bits/stdc++.h>
using namespace std;
int a[100005];
int binary_src(int lo, int hi, int target)
{
    int index=-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(a[mid]==target)
        {
            index=mid;
            hi=mid-1;
        }
        else if(a[mid]<target)
        {
            lo=mid+1;
        }
        else if(a[mid]>target)
        {
            hi=mid-1;
        }
    }
    return index;
}
int main()
{
    int n, i, t, q, ans;
    scanf("%d %d",&n,&q);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1; i<=q; i++)
    {
        scanf("%d",&t);
        ans=binary_src(0,n-1,t);
        printf("%d\n",ans);
    }
    return 0;
}
