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

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i =0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<pair<int,int> > vec;
	int min ,max,j,indn,indx;
	for(j=0;j<k;j++)
	{
		min = a[0];
		max = a[0];
		indn =0; indx=0;
		for(int i =0;i<n;i++)
		{
			if(a[i]>max) {max = a[i]; indx = i;}
			if(a[i]<min) {min = a[i]; indn = i;}
		}//cout<<max<<" "<<min<<endl;
		if((max-min)==0||(max-min)==1) break;
		vec.push_back(make_pair(indx,indn));
		a[indx]--; a[indn]++;
	}max = a[0] ; min = a[0];
	for(int i =0;i<n;i++)
		{
			if(a[i]>max) {max = a[i]; }
			if(a[i]<min) {min = a[i]; }
		}
	cout<<max-min<<" "<<j<<endl;
	while(!vec.empty())
	{
		pair<int,int> p;
		p = vec.back();
		vec.pop_back();
		cout<<p.first+1<<" "<<p.second+1<<endl;
	}
}


