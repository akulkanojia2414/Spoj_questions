#include<stdio.h>
int t,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&b,&b);
		if(b&1) printf("1.000000\n");
		else printf("0.000000\n");
	}
}


