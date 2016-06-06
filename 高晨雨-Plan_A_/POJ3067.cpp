//对L按升序排序后，求R的逆序数就是相交的点数
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define Max 1000005
int T[Max],N,M,K;
struct Node
{
	int R,L;
	int num;
}node[Max];
bool comp(const Node &a,const Node &b)
{
	if(a.L==b.L) return a.R<b.R;
	return a.L<b.L;
}
int lowbit(int x)
{
	return(-x)&x;
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
int update(int x)
{
	while(x<=M)
	{
		T[x]+=1;
		x+=lowbit(x);
	}
}
int main()
{
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&N,&M,&K);
		for(int i=1;i<=K;i++)
		{
			scanf("%d%d",&node[i].L,&node[i].R);
			node[i].num=i;
		}
		memset(T,0,sizeof(T));
		long long ans=0;
		sort(node+1,node+1+K,comp);
		for(int i=1;i<=K;i++)
		{
			update(node[i].R);
			ans+=(Query(M)-Query(node[i].R));
		}
		printf("Test case %d: %lld\n",cas++,ans);
	}
}
