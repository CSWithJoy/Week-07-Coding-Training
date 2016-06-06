//两个树状数组
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

#define maxn  200010

long long cow[maxn];//记录比i的能量小的牛的个数
long long dis[maxn];//记录比i小的牛的距离之和
struct ox{
	int eng;
	int pos;
}c[maxn];//记录每个牛的信息
#include<iostream>

bool cmp(ox a,ox b)//按照能量排序
{
	if(a.eng==b.eng)
		return a.pos<b.pos;
	return a.eng<b.eng;
}

long long sum(long long temp[maxn],int x)
{
	long long s = 0;
	while(x>0)
	{
	  s+=temp[x];
	  x-=(x&-x);
	}
	return s;
}

void add(long long temp[maxn],int x,int add)
{
	while(x<=maxn)
	{
	   temp[x]+=add;
	   x+=(x&-x);
	}
}

int main()
{
	long long ans=0;

	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i].eng>>c[i].pos;
	}

	sort(c+1,c+n+1,cmp);

	memset(cow,0,sizeof(cow));
	memset(dis,0,sizeof(dis));


	for(int i=1;i<=n;i++)//计算每头牛的各种组合的和
	{
		long long total_dis = sum(dis,maxn-1);//所有距离总和
		long long total = sum(dis,c[i].pos);//到牛i的距离总和
		long long cnt = sum(cow,c[i].pos);//排在牛i前的牛的个数

		ans+= c[i].eng * (cnt*c[i].pos-total /*<-前面牛的距离；后面牛的距离->*/+ total_dis-total-(i-cnt-1)*c[i].pos);

		//更新
		add(dis,c[i].pos,c[i].pos);
		add(cow,c[i].pos,1);
	}

	printf("%lld\n",ans);

	return 0;
}
