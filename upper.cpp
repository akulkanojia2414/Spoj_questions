
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
	int b[(n*(n+1))/2 + 1];
	for(int i =0;i<n;i++)
		for(int j=0;j<=i;j++)
		{
			b[(i*i + i)/2 +j ] = a[i][j];
		}
	int u,i,j;
	cin>>u;
	while(u!=0)
	{
		cin>>i>>j;
		cout<<b[(i*i+i)/2 + j ]<<endl;
		cin>>u;
	}
}
