//没看出来怎么用矩阵快速幂，找规律了
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	long long x,y,n,ans;
	cin>>x>>y;
	cin>>n;
	if(n%6==0) ans=(x+1000000007-y+1000000007)%1000000007;
	else if(n%6==1) ans=(x+1000000007)%1000000007;
	else if(n%6==2) ans=(y+1000000007)%1000000007;
	else if(n%6==3) ans=(y+1000000007-x+1000000007)%1000000007;
	else if(n%6==4) ans=(1000000007-x)%1000000007;
	else if(n%6==5) ans=(1000000007-y)%1000000007;
	cout<<ans;
	return 0;
}
