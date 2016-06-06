//树状数组边建树边查询
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MAX 32005
int sum[MAX],level[MAX];
int lowbit(int x)
{
	return (-x)&x;
}
int Query(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=sum[x];
		x-=lowbit(x);
	}
	return ret;
}
void update(int x)
{
	while(x<=32005)
	{
		sum[x]++;
		x+=lowbit(x);
	}
}
int main()
{
	int n,x,y;
	while(scanf("%d",&n)!=EOF)
	{
		memset(sum,0,sizeof(sum));
		memset(level,0,sizeof(level));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			level[Query(x+1)]++;
			update(x+1);
		}
		for(int i=0;i<n;i++)
			cout<<level[i]<<endl;
	}
	return 0;
}
