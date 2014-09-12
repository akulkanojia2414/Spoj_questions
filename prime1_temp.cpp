#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include<cstdio>
using namespace std;

vector<int> prime;

void prime_n()
{
	vector<bool> temp(50000,true);
	int i,j,k,m,n;

	n=50000;
	m=(int)sqrt(n);

	for(i=4;i<n;i=i+2)
		temp[i]=false;

	for(i=3;i<=m;i=i+2){
		if(temp[i]){
			for(j=i*i;j<n;j=j+i)
				temp[j]=false;
		}
	}

	prime.push_back(2);
	for(i=3;i<n;i=i+2){
		if(temp[i])
			prime.push_back(i);
	}

	temp.clear();
}

void solution(int m,int n)
{
	if(m==1)
		m=2;

	vector<bool> temp(n-m+10,true);
	int i,j,k,l,x;

	x=(int)sqrt(n);
	for(i=0;prime[i]<=x;i++){
		j=prime[i]*prime[i];
		if(j<m){
			l=(m+prime[i]-1)/prime[i];
			j=prime[i]*l;
		}
		for(k=j-m;k<(n-m+10);k=k+prime[i])
			temp[k]=false;
	}


	for(i=0;i<(n-m+1);i++){
		if(temp[i])
			printf("%d\n",i+m);
	}
	temp.clear();
}

int main()
{
	int t,m,n;

	prime_n();

	scanf("%d",&t);

	while(t){
		t=t-1;
		scanf("%d%d",&m,&n);
		solution(m,n);
		printf("\n");
	}

	return 0;
}
