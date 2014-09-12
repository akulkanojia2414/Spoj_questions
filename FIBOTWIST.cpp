
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
#include <limits>


#define abs(x) ((x)>=0? (x):(-x))
#define gc getchar()
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
const int mod = 1000000007;
ll f[2][2];
void mat()
{
	f[0][0] =1;
	f[0][1]=1;
	f[1][0] = 1;
	f[1][1]=0;
}
void multiply(ll f[2][2],ll m[2][2])
{
	ll w,x,y,z;
		w = ((f[0][0]*m[0][0])%mod + (f[0][1]*m[1][0])%mod)%mod;
		x = ((f[0][0]*m[0][1])%mod +(f[0][1]*m[1][1])%mod)%mod;
		y = ((f[1][0]*m[0][0])%mod + (m[1][0]*f[1][1])%mod)%mod;
		z = ((f[1][0]*m[0][1])%mod + (f[1][1]*m[1][1])%mod)%mod;
		f[0][0] = w%mod;
		f[0][1] = x%mod;
		f[1][0] = y%mod;
		f[1][1] = z%mod;
}
void power(int n)
{	ll m[2][2] ;
	m[0][0] = 1;
	m[0][1] = 1;
	m[1][0] = 1;
	m[1][1] =0;
	if(n==1||n==0) return;
	power(n/2);
	multiply(f,f);
	if(n&1)  multiply(f,m);

}
ll temp,temp1;
int main()
{
	int t,n,a;
	cin>>t;
	while(t--)
	{
		mat();
		cin>>n>>a;
		power(n);
		temp = f[0][0];
		mat();
		power(a+1);
		temp1 = f[0][0];
		temp1 -= temp;
		if(temp1<0) temp1+=mod;
		cout<<temp1<<endl;

	}
}
