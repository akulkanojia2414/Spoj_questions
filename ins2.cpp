	#include<iostream>
	#include<cmath>
	#include<cstdio>
	using namespace std;

	int get()
	{
	  char c;
	  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
	  bool flag=(c=='-');
	  if(flag)
		c=getchar();
	  int x=0;
	  while(c>='0'&&c<='9')
		{
		  x=x*10+c-48;
		  c=getchar();
		}
	  return flag?-x:x;
	}
	void output(int x)
	{
	  if(x<0)
		{
		  putchar('-');
		  x=-x;
		}
	  int len=0,data[10];
	  while(x)
		{
		  data[len++]=x%10;
		  x/=10;
		}
	  if(!len)
		data[len++]=0;
	  while(len--)
		putchar(data[len]+48);
	  putchar('\n');
	}

	int main()
	{
		int temp;	int t,n;
		t = get();
		while(t--)
		{
			n =  get();
		 temp = (int)n/3;
			output(temp);
		}
		return 0;
	}

