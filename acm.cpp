
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
int a[101][101],b[250][250];ll c[250][250];
int main()
{
	int t,n,m,M,N,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		N = 2*n - 1;
		M = 2*m -1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
					cin>>a[i][j];
			}
		}
		for(i=0;i<N;i++)
		{
			for( j =0;j<M;j++)
			{
				if(i%2==1||j%2==1)
				b[i][j] = 0;
				else b[i][j] = a[i/2][j/2];

			}
		}
		ll sum ,max;
		int k =0;
		for(i=0;i<N;i++)
		{max = -10000000;
			for(j=0;j<M;j++)
			{max = -10000000;
				sum =0; k=1;
				if((i+j)%2==0)
				{sum+= b[i][j];
					while((i-k)>=0 && (i+k)<N && (j-k)>=0 && (j+k)<M)
					{
						sum += b[i-k][j-k] + b[i-k][j+k] + b[i+k][j-k] + b[i+k][j-k];
						if(sum>max) max = sum;
						k++;
					}
				}
				c[i][j] = max;
			}
		} max = -INT_MAX;
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{cout<<b[i][j]<<" ";
				if(c[i][j] >max ) max = c[i][j];
			}cout<<endl;
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{cout<<c[i][j]<<" ";
				//if(c[i][j] >max ) max = c[i][j];
			}cout<<endl;
		}
		cout<<max<<endl;
		CLR(a);CLR(b);CLR(c);
	}
}


