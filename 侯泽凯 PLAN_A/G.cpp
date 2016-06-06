//树状数组+离散化
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 500005;

struct Node
{
	int val;
	int pos;
}node[N];

int c[N];
int reflect[N];
int n;

bool cmp(Node a,Node b)
{
	return a.val < b.val;
}

void add(int x)
{
	while(x<=n)
	{
		c[x]+=1;
		x+=(x&-x);
	}
}

int sum(int x)
{
	int s=0;
	while (x>0)
	{
		s+=c[x];
		x-=(x&-x);
	}
	return s;
}

int main()
{
	while (cin>>n&&n)
	{
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&node[i].val);
			node[i].pos=i;
		}

		sort(node+1,node+n+1,cmp);

		//离散化（也顺便解决了0的问题）
		//因为数据范围为0~ 999,999,999,所以需要开999999999这么大的数组，是不允许的
		//而数据最大为500,000个，
		//且求逆序数的时候只需要关心大小问题
		for (int i=1;i<=n;i++)
		{
			reflect[node[i].pos]=i;
		}

		memset(c,0,sizeof(c));

		long long ans=0;
		for (int i=1;i<=n;i++)
		{
			add(reflect[i]);
			ans+=i-sum(reflect[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
