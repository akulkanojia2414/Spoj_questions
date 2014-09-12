#include<cstdio>
#include<iostream>
#include<cstring>
#include<sstream>
#include<stdlib.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<queue>
#include<iomanip>
#include<ctype.h>
#include<complex>
#include<utility>
#include<functional>
#include<bitset>
#include<numeric>
#include<cassert>
#include<limits>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	string str;
    cin>>str;
    char ch;
    char str1[2*n+1];
    char str2[2*n+1];
	for(int i=0; i<n; i++)
	{
		ch=str[i];
		cout<<ch<<endl;
		if(ch > '9')
		{
			ch-=55;
		}
		 else
		 {
			ch -= '0';
		 }
		 cout<<(int)ch<<endl;
		str2[2*i+1]=ch%2?1:0;
		ch>>=1;
		cout<<(int)ch<<endl;
		str2[2*i]=ch%2?1:0;
		ch>>=1;
		cout<<(int)ch<<endl;
		str1[2*i+1]=ch%2?1:0;
		ch>>=1;
		cout<<(int)ch<<endl;
		str1[2*i]=ch%2?1:0;
		cout<<endl;
	  }
	  cout<<(int)ch<<endl;
	ch=0;
	for(int i=2*n-1; i>=0; i--)
	{
		ch = str1[i] +str2[i] + ch;
		cout<<(int)ch<<endl;
		if(ch%2==1)
		 str1[i]='1';
		else
		 str1[i]='0';
		if (ch>1)
		 ch = 1;
		else
		 ch=0;
	}
	str1[2*n] = 0;
	cout<<str1<<endl;
	return 0;
}
