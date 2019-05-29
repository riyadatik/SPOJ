#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7
double F(double x, double y)
{
    double uu, vv;
    uu=y*x;
    vv=pow(x,uu);
    return (x*vv);
}
double bisection(double lo, double hi, double c, double p)
{
    double mid, res;
    while(fabs(hi-lo)>eps)
    {
        mid=(lo+hi)/2.0;
        res=F(mid,c);
        if(res>p)
        {
            hi=mid;
        }
        else if(res<p)
        {
            lo=mid;
        }
    }
    return mid;
}
int main()
{
    int n, i;
    double p, c, ans;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lf%lf",&p,&c);
        ans=bisection(0.0,15,c,p);
        printf("%lf\n",ans);
    }
    return 0;
}
