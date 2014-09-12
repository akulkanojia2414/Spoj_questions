
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

int main()
{
	int t,a,b;
	cin>>t;
	int temp=t;
	while(t--)
	{
		cin>>a>>b;
		int m[a][b],sum[a],sum1[b];
		for(int i =0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				cin>>m[i][j];
				if(j==0) sum[i]=m[i][j];
				else sum[i]+=m[i][j];
			}
		}
		for(int j=0;j<b;j++)
		{
			for(int i =0;i<a;i++)
			{
				if(i==0) sum1[j]=m[i][j];
				else sum1[j]+=m[i][j];
			}
		}
		bool f1=false,f2=true,f3=true;
		for(int i =0;i<a;i++) {if(sum[i]==0) f2 = false; if(sum[i]>=b) f3 = false;}
		for(int j=0;j<b;j++) {if(sum1[j]>=1) {f1 =true; break;}}
		int d =0 ;
		d|=(int)f1;
		d<<=1;
		d|=(int)f2;
		d<<=1;
		d|=(int)f3;
		cout<<"Case "<<temp-t<<": "<<d<<endl;
	}
}
