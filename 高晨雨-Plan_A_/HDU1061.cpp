#include<iostream>
#include<stdio.h>
using namespace std;
int pow(int a,int b,int Mo)
{
	long long ans=1;
	long long x=a%Mo;
	while(b!=0)
	{
		if(b&1) ans=(ans*x)%Mo;
		x=(x*x)%Mo;
		b>>=1;
	}
	return ans%Mo;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a;
		cin>>a;
		cout<<pow(a,a,10)<<endl;
	}
	return 0;
}
