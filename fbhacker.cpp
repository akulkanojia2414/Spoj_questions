
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
char a[20];
int main()
{
	int t;
	cin>>t;
	for(int j =1;j<=t;j++)
	{
		cin>>a;
		int len = strlen(a);
		int start = a[0] -'0';
		int maxi = -INT_MIN,mini = INT_MAX;
		int indi,indj;
		for(int i=1;i<len;i++)
		{
			if(mini>=a[i]-'0' && a[i] !='0') {mini = a[i]-'0'; indi = i;}
			if(maxi<=a[i]-'0') {maxi = a[i]-'0'; indj =i;}
		}
		char smallest[20],largest[20];
		strcpy(smallest,a);
		strcpy(largest,a);
		if(start>mini)
		{
			smallest[0] = mini + '0';
			smallest[indi] = a[0];
		}
			if(start<maxi)
		{
			largest[0] = maxi + '0';
			largest[indj] = a[0];

		}
		printf("Case #%d: %s %s\n",j,smallest,largest);

	}
}


