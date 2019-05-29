#include<bits/stdc++.h>
using namespace std;
int n;
double res3;
struct info{
    double a,b;
}g[50005];
double F(double mid)
{
    double res=0, res1;
    for(int i=0; i<n; i++)
    {
        res1=(((mid-g[i].a)*(mid-g[i].a))+((0-g[i].b)*(0-g[i].b)));
        res1=sqrt(res1);
        res=max(res,res1);
    }
    return res;
}
double ternary_src(double lo, double hi)
{
    double mid1, mid2, res1, res2, ans;
    int c=50;
    res3=200000000.0;
    while(c--)
    {
        mid1=lo+((hi-lo)/3.0);
        mid2=hi-((hi-lo)/3.0);
        res1=F(mid1);
        res2=F(mid2);
        if(res1<res2)
        {
            if(res1<res3)
            {
                ans=mid1;
                res3=res1;
            }
            hi=mid2;
        }
        else
        {
            if(res2<res3)
            {
                ans=mid2;
                res3=res2;
            }
            lo=mid1;
        }
    }
    return ans;
}
int main()
{
    int i;
    double x, y, ans, mx, mn;
    while(scanf("%d",&n)==1&&n!=0)
    {
        mx=0;
        mn=200000000;
        for(i=0; i<n; i++)
        {
            scanf("%lf %lf",&x,&y);
            g[i].a=x;
            g[i].b=y;
            mx=max(mx,x);
            mn=min(mn,x);
        }
        ans=ternary_src(mn,mx);
        printf("%.9lf %.9lf\n",ans,res3);
    }
    return 0;
}
