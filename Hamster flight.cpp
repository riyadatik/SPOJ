#include<bits/stdc++.h>
using namespace std;
#define LL long long int
const double PI=acos(-1);
double v, k1, k2;
double F1(double mid)
{
    return (v*v*sin(mid)*sin(mid))/20;
}
double F2(double mid)
{
    return (v*v*sin(2*mid))/10;
}
double F(double x, double y)
{
    return ((k2*x)+(k1*y));
}
double ternary_src(double lo, double hi)
{
    LL c=200;
    double mid1, mid2, ans, res1, res2, res=-1, x1, y1, x2, y2;
    while(c--)
    {
        mid1=lo+(hi-lo)/3;
        mid2=hi-(hi-lo)/3;
        x1=F1(mid1);
        y1=F2(mid1);
        res1=F(x1,y1);
        x2=F1(mid2);
        y2=F2(mid2);
        res2=F(x2,y2);
        if(res1>res)
        {
            res=max(res,res1);
            ans=mid1;
        }
        if(res2>res)
        {
            res=max(res,res2);
            ans=mid2;
        }
        if(res1>=res2)
        {
            hi=mid2;
        }
        else
        {
            lo=mid1;
        }
    }
    return ans;
}
int main()
{
    LL t, i, j, k;
    double ans, mx, x, y, lo, hi;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf%lf%lf",&v,&k1,&k2);
        lo=0.0;
        hi=(90*PI)/180;
        ans=ternary_src(lo,hi);
        x=F1(ans);
        y=F2(ans);
        mx=F(x,y);
        printf("%.3lf %.3lf\n",ans,mx);
    }
    return 0;
}
