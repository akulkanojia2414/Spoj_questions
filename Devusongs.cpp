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
ll a[100001];
vector<ll> even,odd;
int main()
{
	ll n,k,p;
	cin>>n>>k>>p;
	for(int i=0;i<n;i++) {cin>>a[i]; if(a[i]&1) { odd.push_back(a[i]);} else even.push_back(a[i]);}
	vector<ll> vec[k];
	//if(x + y/2 >p) {cout<<"NO"<<endl; return 0;}
	for(int i =0;i<p;i++)
	{	if(even.size()>0){
		vec[i].push_back(even.back());
		even.pop_back();}
		else if(odd.size()>0){
		vec[i].push_back(odd.back()); odd.pop_back();
		vec[i++].push_back(odd.back()); odd.pop_back();
		}
	}
	bool flag = true;
	for(int i =p;i<k;i++)
	{
		if(odd.size()==0) {flag = false; break;}
		vec[i].push_back(odd.back()); odd.pop_back();
	}
	int i =p;
	while(odd.size()>1)
	{
		vec[i].push_back(odd.back()); odd.pop_back();
		vec[i++].push_back(odd.back()); odd.pop_back();
	}
	i =0;
	if(odd.size()==1)
	{
		for(int j=p;j<k;j++)
		{
			if(vec[j].size()%2==0) {vec[j].push_back(odd.back()); odd.pop_back();}
		}
	}
	while(even.size()>0)
	{
		vec[i++].push_back(even.back()); even.pop_back();
	}

	if(flag == false||odd.size()>0) cout<<"NO"<<endl;
	if(flag) {cout<<"YES"<<endl;
		for(int j=0;j<k;j++)
		{
			cout<<vec[j].size()<<" ";
			while(vec[j].size()>0) {cout<<vec[j].back()<<" "; vec[j].pop_back();}
			cout<<endl;
		}
	}

}


