//start的变型题目
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX 100005
int ans[MAX],Tree[MAX],len;
struct COW
{
	int S;
	int E;
	int num;
}cow[MAX];
int lowbit(int x)
{
	return (-x)&x;
}
int Qurey(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=Tree[x];
		x-=lowbit(x);
	}
	return ret;
}
void update(int x,int d)
{
	while(x<=len)
	{
		Tree[x]+=d;
		x+=lowbit(x);
	}
}
bool comp(const struct COW &x,const struct COW &y)
{
	if(x.E==y.E) return x.S<y.S;
	return x.E>y.E;
}
int main()
{
	while(scanf("%d",&len)!=EOF)
	{
		if(!len) break;
		for(int i=0;i<len;i++)
		{
			//cin>>cow[i].S>>cow[i].E;
			scanf("%d%d",&cow[i].S,&cow[i].E);
			cow[i].S++;
			cow[i].E++;
			cow[i].num=i;
		}
		memset(Tree,0,sizeof(Tree));
		sort(cow,cow+len,comp);
		for(int i=0;i<len;i++)
		{
			if(i>0&&cow[i].S==cow[i-1].S&&cow[i].E==cow[i-1].E)
				ans[cow[i].num]=ans[cow[i-1].num];
			else
				ans[cow[i].num]=Qurey(cow[i].S);
			update(cow[i].S,1);
		}
		for(int i=0;i<len;i++)
			printf("%d%c",ans[i],i==(len-1)?'\n':' ');
	}
	return 0;
}
