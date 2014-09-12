#include<cstdio>
using namespace std;
unsigned long long dp[1000000];
int main()
{
	dp[0]=0;
	dp[1]=1;
	for(int i =2;i<100000;i++)
	{
		dp[i]= dp[i-1]+dp[i-2];
		printf("%ull\n",dp[i]);
	}
}
