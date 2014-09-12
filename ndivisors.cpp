
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <queue>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits.h>
#include <cstdlib>
#include <stack>


#define abs(x) ((x)>=0? (x):(-x))
#define gc getchar_unlocked
#define s(x) scanf("%d",&x)
#define sil(x) scanf("%llu",&x)
#define sd(x) scanf("%ld",&x)
#define in(s) cin>>s
#define FOR(i,a,b) for( typeof(a) i=(a); i<(b); ++i) // exclusive for
#define FORR(i,a,b) for( typeof(a) i=(a-1) ; i>=(b); --i)
#define REP(k,a,b) for(typeof(a) k=(a); k <= (b); ++k) // inclusive for
#define REPR(i,a,b) for( typeof(a) i=(a) ; i>=(b); --i)
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define SZ(x) ((int)((x).size()))
#define SRT(v) std::sort(ALL(v))
#define CTN(x) std::cout<<x<<'\n' //cout with newline
#define CTS(x) std::cout<<x<<" " //cout with space
#define CT(x) std::cout<<x
#define CLR(x) std::memset(x,0,sizeof(x))
#define FILL(x,n) std::fill_n(x,sizeof(x),n)
#define T(t) int t=read<int>();// while(t--)
#define DBGA(x,n) {for(int i=0;i<n;i++) cout<<x[i]<<" "; cout<<"\n";}
#define REC(x) clock_t x=clock()
#define CPS CLOCKS_PER_SEC
#define TM(x,y) CTN(((double)(y-x)/CPS));


typedef std::vector<int> VI;
typedef std::vector<long long int> VL;
typedef std::vector<unsigned long long int> VULL;
typedef std::vector<std::string> VS;
typedef std::map<int,int> MI;
typedef std::pair<int,int> PII;
typedef std::string str;
typedef unsigned long long ull;
typedef long long ll;
typedef long int li;


using namespace std;


vector<int> prime;
bool a[32001] ={0};

int get()
{
  register char c;
  while(c=gc(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=gc();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=gc();
    }
  return flag?-x:x;
}
void output(int x)
{
  if(x<0)
    {
      putchar_unlocked('-');
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
    putchar_unlocked(data[len]+48);
  putchar_unlocked('\n');
}

int temp,temp1,ctr=0,c,b,n,x,k,l;
int main()
{	//seive

	for(int i =3;i<=sqrt(32000);i+=2)
	{
		for(int j=i*i;j<=32000;j+=i)
		{
			a[j]=true;
		}
	}

	//vector for prime nos.
	prime.push_back(2);
	for(int i =3;i<=32000;i+=2) if(a[i]==false) prime.push_back(i);



	c = get();
	b=get();
	n = get();
	//cin>>c>>b>>n;
	 x = sqrt(b);
	vector<int> vec(b-c+10);
	vector<int> actual(b-c+10);
	for(int i =0;i<b-c+1;i++) {vec[i] = 1;actual[i] = c+i;}
	for(int i =0;prime[i]<=x;i++)
	{	 k = prime[i]<<1;
		if(k<c) {  l = (c-1)/prime[i]+1;
				k=prime[i]*l;}
		for(int j=k;j<=b;j+=prime[i])
		{
			temp =0;
			 //cout<<temp1<<' '<<actual[j-c]<<endl;
			while(actual[j-c]%prime[i]==0)
			{
				actual[j-c]/=prime[i];	//cout<<actual[j-c]<<endl;
				temp++;
			}
			vec[j-c] *=(temp+1);


		}
	}
	for(int j =0;j<b-c+1;j++)
	{
		if(actual[j]>1) vec[j]<<=1;
		if(vec[j] == n ) ctr++;
		//cout<<j+c<<" "<<vec[j]<<endl;
	}
	output(ctr);
	//cout<<ctr<<endl;
}


