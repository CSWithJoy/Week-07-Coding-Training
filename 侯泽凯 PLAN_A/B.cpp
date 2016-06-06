//6%6=0TAT
#include<iostream>
using namespace std;

#define mod 1000000007

int num[10];

int main()
{
	int n;
	cin>>num[1]>>num[2];
	cin>>n;
	n%=6;
	for(int i=3;i<=6;i++)
	{
		num[i]=num[i-1]-num[i-2];
	}
	int ans=num[(n+5)%6+1];
	//cout<<n%6<<endl;
	//cout<<ans<<endl;
	//(F[(n+5)%6] + 1000000007) % 1000000007;
	while(ans<0)ans+=mod;

	ans%=mod;

	cout<<ans<<endl;
	return 0;
}
