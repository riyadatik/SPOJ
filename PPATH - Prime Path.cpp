#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
int visited[10000];
int level[10000];
int prime[10000];
void seive()
{
    int i, j;
    for(i=4; i<=10000; i=i+2)
        prime[i]=1;
    for(i=3; i<=sqrt(10000); i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i; j<=10000; j=j+i+i)
            {
                prime[j]=1;
            }
        }
    }
    prime[1]=1;
}

int nmu(int p, int nm, int i)
{
    int one, two, three, four;
    one=nm%10; nm=nm/10;
    two=nm%10; nm=nm/10;
    three=nm%10; nm=nm/10;
    four=nm%10; nm=nm/10;
    if(p==1)
    {
        return (four*1000)+(three*100)+(two*10)+i;
    }
    else if(p==2)
    {

        return (four*1000)+(three*100)+(i*10)+one;
    }
    else if(p==3)
    {
        return (four*1000)+(i*100)+(two*10)+one;
    }
    else if(p==4)
    {
        return (i*1000)+(three*100)+(two*10)+one;
    }
}
void bfs(int n, int m)
{
    queue<int>q;
    q.push(n);
    visited[n]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int num=u;
        for(int i=0; i<=9; i++)
        {
            int v;
            v=nmu(1,u,i);
            if(prime[v]==0&&visited[v]==0)
            {
                visited[v]=1;
                level[v]=level[u]+1;
                q.push(v);
                if(v==m)
                {
                    printf("%d\n",level[v]);
                    return;
                }
            }
            int v1=nmu(2,u,i);
            if(prime[v1]==0&&visited[v1]==0)
            {
                visited[v1]=1;
                level[v1]=level[u]+1;
                q.push(v1);
                if(v1==m)
                {
                    printf("%d\n",level[v1]);
                    return;
                }
            }
            int v2=nmu(3,u,i);
            if(prime[v2]==0&&visited[v2]==0)
            {
                visited[v2]=1;
                level[v2]=level[u]+1;
                q.push(v2);
                if(v2==m)
                {
                    printf("%d\n",level[v2]);
                    return;
                }
            }
            int v3=nmu(4,u,i);
            if(prime[v3]==0&&visited[v3]==0&&i>0)
            {
                visited[v3]=1;
                level[v3]=level[u]+1;
                q.push(v3);
                if(v3==m)
                {
                    printf("%d\n",level[v3]);
                    return;
                }
            }
        }
    }
    printf("Impossible\n");
}
int main()
{
    int t, n, m, i, j, k;
    seive();
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d",&n,&m);
        if(n==m) printf("0\n");
        else
        bfs(n,m);
        mem(visited,0);
        mem(level,0);
    }
    return 0;
}
