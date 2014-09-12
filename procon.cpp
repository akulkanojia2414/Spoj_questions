
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
bool myfunction (int i,int j) { return (i<j); }
int a[1000000];
int c[1000000];
int dp[1000000];
int main()
{
	int n;
	cin>>n;
	for(int i =0;i<n;i++) cin>>a[i];
	int sz = 1;
	c[1] = a[0];
	dp[0] = 1;
	for( int i = 1; i < n; i++ ) {
   if( a[i] < c[1] ) {
      c[1] = a[i];
      dp[i] = 1;
   }
   else if( a[i] >= c[sz] ) {
      c[sz+1] = a[i];
      dp[i] = sz+1;
      sz++;
   }
   else {
      int k = binary_search( c,c+100001,a[i] ,myfunction);
      c[k] = a[i];
      dp[i] = k;
		cout<<k<<endl;
   }
}
	int max =0;
	for(int i =0;i<n;i++)
	{
		if(dp[i] > max) max = dp[i];
	}
	cout<<max<<endl;
	CLR(a);
	CLR(c); CLR(dp);
}

