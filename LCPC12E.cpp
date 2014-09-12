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

vector<int> prime;
int a[50001]={0};
void prime_done()
{
	a[0] = true;
		a[1] = true;
	for(long long i=4;i<=50000;i+=2) a[i] =true;
	for(long long i =3;i<=sqrt(50000);i+=2){
		for(long long j=i*i;j<=50000;j+=i){
			a[j]=true;
		}
	}
	for(int i=2;i<=50000;i++)
	{
		if(!a[i]) prime.push_back(i);
	}
}

void solution(int m,int n)
{
	vector<bool> temp(n-m+1,false);
	int x = sqrt(n);
	long long j,l;
	for(int i =0;prime[i]<=x;i++)
		{
			if(m==1) m=2;
			j = prime[i]*prime[i];
			if(j<m)
				{
					l = (m-1)/prime[i]+1;
					j = prime[i]*l;

				}
			for(int k=j;k<=n;k+=prime[i])
				{
					temp[k-m] = true;
				}

		}
	for(int i =0;i<n-m+1;i++)
		{
			if(!temp[i]) printf("%d\n",i+m);
		}
}

int main()
{
	prime_done();
	int t;
long long m,n;
	cin>>t;
while(t--)
	{
		cin>>m>>n;
//
		solution(m,n);
		cout<<endl;
	}
}

