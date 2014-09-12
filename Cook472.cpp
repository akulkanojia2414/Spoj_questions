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

long long unsigned read()
{
        long long unsigned num=0;
		register char ch=gc();
        while(ch<'0' || ch>'9')
                ch=gc();
        while(ch>='0' && ch<='9')
        {
                num=(num<<1)+(num<<3)+(ch-48);
                ch=gc();
        }
        return num;
}
void output(ll x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  ll len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar_unlocked(data[len]+48);
  putchar_unlocked(' ');
}
vector<ll> vec[2];
int main()
{
	register ll n,x,y,c=0;
	 n = read();
	for(int i =0;i<n;i++)
	{
		x = read();
		y = read();
		c+=x;
		if(x==1) vec[0].push_back(y);
		if(x==2)vec[1].push_back(y);
	}

	sort(vec[0].rbegin(),vec[0].rend());
	sort(vec[1].rbegin(),vec[1].rend());
	vec[0].push_back(0);
	vec[1].push_back(0);
	vector<ll> P(c+1,0);
	vector<ll> Q(c+1,0);
	vector<ll> R(c+1,0);
	for(int i=1;i<=c;i++)
	{
		if(i==1)
		{
			if(vec[0].size()>0)
			{
				P[i] = vec[0][0];
				Q[i] = 1;
			}
		continue;
		}
		P[i] =P[i-1];
		Q[i]=Q[i-1];
		R[i] =R[i-1];
		if(Q[i-1]<vec[0].size()) {P[i] = vec[0][Q[i-1]] +P[i-1]; Q[i] = Q[i-1] +1; R[i] = R[i-1];}
		if(R[i-2]<vec[1].size())
		{
			if(P[i-2] + vec[1][R[i-2]] >P[i]) {P[i] = vec[1][R[i-2]] + P[i-2]; R[i] = R[i-2] +1; Q[i] = Q[i-2];}
		}
	}
	for(int i =1;i<=c;i++) output(P[i]);

}


