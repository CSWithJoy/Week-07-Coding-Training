//star的变形
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=100010;
int c[MAXN];//树状数组，数组id为关键码
int n;
int cnt[MAXN];//记录结果

struct Node
{
    int s,e;
    int index;
}node[MAXN];

//先按照E从大到小排序，E相同则按照S从小到大排序
bool cmp(Node a,Node b)
{
    if(a.e==b.e)return a.s<b.s;
    return a.e>b.e;
}

void add(int i,int val)
{
    while(i<=n)
    {
        c[i]+=val;
        i+=(i&-i);
    }
}

int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=(i&-i);
    }
    return s;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&node[i].s,&node[i].e);
            node[i].index=i;
        }

        sort(node+1,node+n+1,cmp);

        memset(c,0,sizeof(c));
        memset(cnt,0,sizeof(cnt));

        cnt[node[1].index]=0;

        //更新的技巧start处更新数值。就排除了交叉区间的问题
        add(node[1].s+1,1);

        for(int i=2;i<=n;i++)
        {
            if( node[i].e==node[i-1].e && node[i].s==node[i-1].s )
			{
				cnt[node[i].index]=cnt[node[i-1].index];
			}
            else
			{
				cnt[node[i].index]=sum(node[i].s+1);
			}
            add(node[i].s+1,1);
        }

        printf("%d",cnt[1]);
        for(int i=2;i<=n;i++)
          printf(" %d",cnt[i]);
        printf("\n");
    }
    return 0;
}
