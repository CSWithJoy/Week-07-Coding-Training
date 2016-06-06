//模板题
#include<iostream>
using namespace std;

int qmod(long long a,long long b,int c)
{
	int ans=1;
	a%=c;
	while(b>0)
	{
		if(b&1)
		{
			ans = (ans * a) % c;
		}
        b = (b>>1);
        a = (a*a) % c;
	}
	return ans;
}

int main()
{
	long long n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<qmod(n,n,10)<<endl;
	}
	return 0;
}
