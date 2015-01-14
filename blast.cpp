
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
int dp[2002][2002]={0};
int abs(int a) {if(a>=0) return a;return -a;}
int main()
{
	char a[2001],b[2001];
	int k;
	cin>>a>>b>>k;
	int len1,len2,d1,d2,d3,min;
	len1= strlen(a);
	len2 = strlen(b);
	for(int i =0;i<=len1;i++)
	{
		dp[i][0] = k*i;
	}
	for(int i =0;i<=len2;i++)
	{
		dp[0][i] = k*i;
	}
	for(int i =1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			d1 = abs(a[i-1] - b[j-1]) + dp[i-1][j-1];
			d2 = dp[i-1][j] + k;
			d3 = dp[i][j-1] + k;
			int temp;
				if(d1<=d2&&d1<=d3) temp = d1;
				else if(d2<=d1&&d2<=d3) temp = d2;
				else if(d3<=d1&&d3<=d2)temp = d3;
				dp[i][j] = temp;
		}
	}
	cout<<dp[len1][len2]<<endl;
}


