//开两个树状数组，一个存距离和，一个存每头牛前面的牛的个数
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 20010
struct node
{
	int x,v;
	bool operator<(const node &b) const
	{
		return v<b.v;
	}
}cow[MAX];
int dit[MAX],num[MAX];
int lowbit(int x)
{
	return x&(-x);
}
int Query(int *a,int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=a[x];
		x-=lowbit(x);
	}
	return ret;
}
int update(int *a,int x,int d)
{
	while(x<MAX)
	{
		a[x]+=d;
		x+=lowbit(x);
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&cow[i].v,&cow[i].x);
		}
		sort(cow,cow+n);
		long long ans=0;
		long long sum=0;
		memset(dit,0,sizeof(dit));
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++)
		{
			int x=cow[i].x,v=cow[i].v;
			int cnt=Query(num,x);
			int dist=Query(dit,x);
			ans+=(long long)v*(cnt*x-dist+sum-(i-cnt)*x-dist);
			update(num,x,1);
			update(dit,x,x);
			sum+=x;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
