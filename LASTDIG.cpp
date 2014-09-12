#include<cstdio>
#include<iostream>
using namespace std;

int pow(int a,int b,int n)
{
	if(b==0) return 1;
	if(b==1) return a%n;
	int temp = pow(a,b/2,n)%n;
	if(b%2==0) return temp*temp%n;
	else return temp*temp*a%n;
}

int main()
{
	int t,a,d;
	long long b;
	scanf("%d",&t);
	while(t--)
	{
		cin>>a>>b;
		if(b==0){ cout<<1<<endl;continue;}
		d = b%4;
		if(d==0) d=4;
		//cout<<d;
		printf("%d\n",(int)(pow(a,d,10)));
	}
}
