#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;
#define pii pair<int, int>
#define piii pair<pii, pii>
#define mem(x,y) memset(x,y,sizeof(x))
#define sc scanf
#define pf printf
#define pb push_back
#define pu push
#define uu first
#define vv second
#define DIST(x1,y1,x2,y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define pi acos(-1)
#define ull unsigned long long int
#define mx 100002
struct info{
    ll zero, one, two, prop;
}tree[mx*4];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].zero=1;
        return;
    }
    int L=node*2;
    int R=node*2+1;
    int mid=(b+e)/2;
    init(L, b, mid);
    init(R, mid+1, e);
    tree[node].zero=tree[L].zero + tree[R].zero;
}

void propagate(int carry, int node)
{
    ll a0=tree[node].zero;
    ll a1=tree[node].one;
    ll a2=tree[node].two;
    if(carry==1)
    {
        tree[node].zero=a2;
        tree[node].one=a0;
        tree[node].two=a1;
    }
    else if(carry==2)
    {
        tree[node].zero=a1;
        tree[node].one=a2;
        tree[node].two=a0;
    }
}

void update(int node, int b, int e, int i, int j)
{
    if(e<i || b>j)
        return;
    if(b>=i&&e<=j)
    {
        tree[node].prop+=1;
        tree[node].prop%=3;

        ll a0=tree[node].zero;
        ll a1=tree[node].one;
        ll a2=tree[node].two;

        tree[node].zero=a2;
        tree[node].one=a0;
        tree[node].two=a1;
        return;
    }
    int L=node*2;
    int R=node*2+1;
    int mid=(b+e)/2;
    update(L, b, mid, i, j);
    update(R, mid+1, e, i, j);
    tree[node].zero=tree[L].zero + tree[R].zero;
    tree[node].one=tree[L].one + tree[R].one;
    tree[node].two=tree[L].two + tree[R].two;
    propagate(tree[node].prop%3, node);
}

ll query(int node, int b, int e, int i, int j, int carry)
{
    if(e<i||b>j)return 0;
    if(b>=i&&e<=j){
        ll a=carry%3;
        if(a==0)return tree[node].zero;
        else if(a==1)return tree[node].two;
        else if(a==2) return tree[node].one;
    }

    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;

    ll p1=query(left, b, mid, i, j, carry+tree[node].prop);
    ll p2=query(right, mid+1, e, i, j, carry+tree[node].prop);

    return p1+p2;
}

int main()
{
    ll n, i, x, u, v, q;
    scanf("%lld %lld",&n,&q);
    init(1, 1, n);
    for(i=1; i<=q; i++)
    {
        scanf("%lld %lld %lld",&x,&u,&v);
        u++;
        v++;
        if(x==0)
        {
            update(1, 1, n, u, v);
        }
        else if(x==1)
        {
            ll ans=query(1, 1, n, u, v, 0);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
