#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;

long long tree[1005];
int n,m,k;

struct rode{
	int e;
	int w;
}r[1005*1005];

bool cmp(rode a,rode b)
{
	if(a.e==b.e)
		return a.w<b.w;
	return a.e<b.e;
}

void add(int i,int x)
{
	while(i<=m)
	{
		tree[i]+=x;
		i+=(i&-i);
	}
}


long long sum(int i)
{
	long long s=0;
	while(i>0)
	{
		s+=tree[i];
		i-=(i&-i);
	}
	return s;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&r[i].e,&r[i].w);//cin>>r[i].e>>r[i].w;
		}
		sort(r,r+k,cmp);

		long long ans=0;

		memset(tree,0,sizeof(tree));

		for(int i=0;i<k;i++)
		{
			add(r[i].w,1);
			ans+=(sum(m)-sum(r[i].w));
		}

		printf("Test case %d: %lld\n",z,ans);
	}
	return 0;
}
