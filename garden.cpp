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

#define mod 1000000007
using namespace std;


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
void output(ll x)
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
int powi(int a,int b)
{
	if(b==0) return 1;
	if(b==1) return a%mod;
	int temp = pow(a,b/2);
	if(b%2==0) return temp*temp%mod;
	else return temp*temp*a%mod;
}
int a[1000000];
int ctr[1000000]={0};
bool visited[1000000]={0};
vector<int> vec;
int t,n,idx,j,counti=0;
int g,temp;
bool arr[1000000] = {0};
vector<int> prime;
int main()
{
arr[0] = true;
		arr[1] = true;
	for(long long i =3;i<=sqrt(100000);i+=2){
		for(long long j=i*i;j<=100000;j+=i){
			arr[j]=true;
		}
	}
prime.push_back(2);
for(int i =3;i<=100000;i+=2) if(arr[i]==false) prime.push_back(i);


t = get();
	while(t--)
	{
		n= get();
		for(int i =1;i<=n;i++)
			a[i] = get();
		if(n==1) {output(1);  CLR(a); continue;}

		for(int i =1;i<=n;i++)
		{
		if(visited[i]==false)
		{
			idx = i;
			visited[idx] = true;
			g=1;
			if(a[idx] == i) continue;

			while(a[idx]!=i)
			{
				j= a[idx];
				idx= j;
				visited[idx] = true;
				g++;
			}
			vec.push_back(g);

		}
		}
		ll ans = 1;
		sort(vec.begin(),vec.end());

		while(!vec.empty())
		{
			temp = vec.back();
			vec.pop_back();
			int x = sqrt(temp);
			for(int i =0;prime[i]<=x;i++)
			{counti=0;
				while(temp%prime[i]==0&&temp)
				{
					counti++;
					temp/=prime[i];
				}
				if(counti>ctr[prime[i]]) ctr[prime[i]] = counti;
			}
			if(temp>1) if(ctr[temp]<1) ctr[temp] =1;
		}

		for(int i =2;i<=100000;i++)
		{
			//cout<<i<<" "<<ctr[i]<<endl;
			ans *= powi(i,ctr[i]);
			ans%=mod;
		}
		output(ans);

		CLR(a); CLR(visited); vec.clear(); CLR(ctr);
	}

}


