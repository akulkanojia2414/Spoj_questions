
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
#define FOR(a) for( int i= 0 ; i<(a); ++i) // exclusive for
#define FORR(a) for( int i=(a-1) ; i>=(0); --i)
#define REP(a) for(int k=0; k <= (a); ++k) // inclusive for
#define REPR(a) for( int i=(a) ; i>=(0); --i)
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

#define mod 1000000007
struct sub{
	int parent;
	int rank;
};
typedef struct sub Subset;

Subset subs[100010];
int ans[100010];

int find(int e){
	if(subs[e].parent!=e) subs[e].parent = find(subs[e].parent);
	return subs[e].parent;
}
int uni(int x, int y){
	int rx = find(x),ry = find(y);
	if(subs[rx].rank<subs[ry].rank){
		subs[rx].parent = ry;
	}
	else if(subs[ry].rank<subs[rx].rank)
		subs[ry].parent = rx;
	else{
		subs[ry].parent = rx;
		subs[rx].rank++;
	}
}
int fact[100010];

int main()
{fact[1] = 1; fact[0] = 1;
	for(int i =2;i<=100000;i++)
	{
		fact[i] = (fact[i-1]*i)%mod;
	}
	int n,k,a,b;
	cin>>n>>k;
	for(int i =0;i<n;i++)
	{
		subs[i].rank = 0;
		subs[i].parent = i;
	}
	for(int i =0;i<k;i++)
	{
		cin>>a>>b;
		int x = find(a),y = find(b);
		if(x!=y)
		uni(a,b);
	}
	for(int i =0;i<n;i++)
	{
		ans[subs[i].parent]++;
	}
	int res = 1;
	for(int i =0;i<n;i++)
	{
		res = (res*fact[ans[i]])%mod;
	}
	cout<<res<<endl;
}
