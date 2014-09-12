#include <iostream>
#include <cstdio>
#include<stdio.h>
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
#include <limits>
#include<cstdlib>

#define abs(x) ((x)>=0? (x):(-x))
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
#define gc getchar_unlocked

ll read() {
	ll num=0;
   char ch=gc();
	while(ch<'0' || ch>'9')
		ch=gc();
	while(ch>='0' && ch<='9')
	{
		num=(num<<1)+(num<<3)+(ch-48);
		ch=gc();
	}
	return num;
}


int main()
{
	ll n,m,h;
	vector<pair<ll,ll> > vec;
	n = read();
	m = read();
	h= read();
	ll x,y,count=0;
	for(ll i =0;i<h;i++)
	{
		x = read();
		y = read();
		vec.push_back(make_pair(y,x));
		count+=x;
	}
	if(count<n*m) {printf("Impossible\n"); return 0;}
	sort(vec.begin(),vec.end());
	ll temp = n*m,cost=0;
	ll i =0;
	while(temp>0&&i<h)
	{
		if(vec[i].second>=temp){cost+=temp*vec[i].first; temp=0;}
		else {cost+=vec[i].second*vec[i].first; temp -= vec[i].second; }
		i++;
	}
	printf("%lld\n",cost);
}
