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
int a,b,t;
int c[10000];
int carry;
int ans[10][4010];
int main()
{	int temp,ind;
for(int k =2;k<=9;k++)
{	CLR(c); ind=0; c[ind] = k; ans[k][1] =k;
	for(int i =2;i<4001;i++)
		{carry =0;
			for(int j=0;j<=ind;j++)
			{
				temp = c[j]*k + carry;
				c[j] = temp%10;
				carry = temp /10;
	//			cout<<temp<<" "<<carry<<endl;
				if(carry>0&&j==ind) {c[j+1] = carry; ind++;break;}
			}int count =0;
		for(int j = ind ;j>=0;j--)
		{
				count+=c[j];
		}
		ans[k][i] = count;
		}

}
	cin>>t;
	for(int i =1;i<=t;i++)
	{
		cin>>a>>b;
		if(b==0){cout<<"Case "<<i<<": "<<1<<endl; continue;}
		if(a==1) {cout<<"Case "<<i<<": "<<1<<endl; continue;}
		cout<<"Case "<<i<<": "<<ans[a][b]<<endl;

	}
}


