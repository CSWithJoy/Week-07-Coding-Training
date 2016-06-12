//树状数组求逆序数，注意离散化
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 500005
int T[MAX],reflect[MAX];
int n;
struct Node
{
	int val;
	int pos;
}node[MAX];

bool comp(const Node &a,const Node &b)
{
	return a.val<b.val;
}

int lowbit(int x)
{
	return (-x)&x;
}
int Query(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=T[x];
		x-=lowbit(x);
	}
	return ret;
}
void update(int x)
{
	while(x<=n)
	{
		T[x]+=1;
		x+=lowbit(x);
	}
}
int main()
{
	long long ans;
	while(scanf("%d",&n)!=EOF)
	{
		if(!n) break;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&node[i].val);
			node[i].pos=i;
		}
		sort(node+1,node+1+n,comp);
		memset(T,0,sizeof(T));
		ans=0;
		for(int i=1;i<=n;i++) reflect[node[i].pos]=i;//离散化
		for(int i=1;i<=n;i++)
		{
			update(reflect[i]);
			ans+=(i-Query(reflect[i]));
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
