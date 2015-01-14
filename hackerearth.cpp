
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
int abs(int a)
{
	if(a>=0)
		return a;
	else return -a;
}
int a[1000000];
int main()
{
	int t,n,sum;
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		for(int i =0;i<n;i++)
		{
			cin>>a[i];
		}
		int temp = a[0],temp1=0,j=0;
		for(int i =1;i<n;i++)
		{
			if(temp-a[i]>0)
			{
				temp1 = (temp1+ temp-a[i])%1000000007;
			}
			else
			{
				temp = a[i];
				j=i;
				sum=(sum+temp1)%1000000007;
				temp1=0;
			}
			if(i==(n-1))
			{
				if(temp1>0)
				{
					int sm = temp - a[i];
					temp1 = (temp1-sm*(i-j))%1000000007;
					sum=(sum+temp1)%1000000007;
					temp1=0;
				}
			}
		}
		cout<<sum<<endl;
	}
}


