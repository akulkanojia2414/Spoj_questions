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


#define MAX 10000
#define LMT 100

unsigned flag[MAX/64];
bool prime[10010];
int total;

#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))


void sieve()
{
        unsigned i, j, k;
        for(i=3;i<LMT;i+=2)
                if(!chkC(i))
                        for(j=i*i,k=i<<1;j<MAX;j+=k)
                                setC(j);
        prime[2] = true;

        for(i=3,j=2;i<MAX;i+=2)
        {
                if(!chkC(i))
                {
                    prime[i] = true;
                }
        }
        total = j;
}
ll dp[1001][1001],a[1001][1001],ans[1001][1001];
int main()
{
	sieve();
	ll n,i,j,k,tmp,cnt;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
			tmp = a[i][j];
			cnt=0;
			while(prime[tmp] != true &&tmp <=10000)
			{
				tmp+=k;
				cnt++;
			}
			//cout<<tmp<<cnt<<endl;
			if(tmp<=10000 )
				dp[i][j] = cnt;
			else
				dp[i][j] = 10000;
		}
	}
	ll mini  = 10000 ;
	ll indi,indj;
	for(i =2 ;i<n;i++)
	{
		for(j=2;j<n;j++)
		{

			ans[i][j] = dp[i-1][j-1] + dp[i+1][j-1] + dp[i-1][j+1] +dp[i+1][j+1];
			if(ans[i][j]<mini) {mini = ans[i][j];}
			else ans[i][j] = 0;
		}
	}
	for(i=2;i<n;i++)
	{
		for(j=2;j<n;j++)
		{
			if(ans[i][j] == mini)
			{
				indi=i;
				indj = j;
				break;
			}
		}
	}
	if(mini<10000)
	{
		cout<<"yes"<<endl;
		cout<<mini<<endl;
		cout<<indi<<" "<<indj<<endl;
	}
	else
		cout<<"no"<<endl;
}

